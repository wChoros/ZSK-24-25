// NodeField.cpp

#include "NodeField.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

NodeField::NodeField(const std::string &filepath) {
    ifstream file(filepath);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file: " + filepath);
    }

    string line;
    int i = 0;
    while (getline(file, line)) {
        int j = 0;
        for (char c: line) {
            if (c == '\n') {
                continue;
            }
            nodes.push_back(Node());
            Node &node = nodes.back();
            node.x = j;
            node.y = i;
            if (c == obstacle) {
                node.isObstacle = true;
            }
            j++;
        }
        if (j > width) {
            width = j;
        }
        i++;
    }
    height = i;
    file.close();
}

NodeField::NodeField(const int width, const int height) {
    this->width = width;
    this->height = height;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            nodes.push_back(Node());
            Node &node = nodes.back();
            node.x = j;
            node.y = i;
        }
    }
}

void NodeField::addObstacles(float probability_percentage) {
    for (Node &node: nodes) {
        if (node.isStart || node.isEnd) {
            continue;
        }
        if (rand() % 100 < probability_percentage) {
            node.isObstacle = true;
        }
    }
}

void NodeField::print() {
    cout << "\033[2J\033[1;1H";

    int previousY = -1;
    string printString = "";
    for (Node &node: nodes) {
        if (node.y != previousY) {
            printString += "\n";
        }
        if (node.isObstacle) {
            printString += obstacle;
        } else if (node.isEnd) {
            printString += end;
        } else if (node.isStart) {
            printString += start;
        } else if (node.isPath) {
            printString += path;
        } else if (node.isOpen) {
            printString += open;
        } else if (node.isClosed) {
            printString += closed;
        } else if (node.isCurrent) {
            printString += current;
        } else {
            printString += empty;
        }
        previousY = node.y;
    }
    cout << printString << endl;
}

bool NodeField::findPath(const int startX, const int startY, const int endX, const int endY, const bool printPath) {
    try {
        markPath(startX, startY, endX, endY, printPath);
    } catch (runtime_error &) {
        return false;
    }

    Node *currentNode = findNode(endX, endY);
    while (currentNode->parent != nullptr && !currentNode->isStart) {
        currentNode->isPath = true;
        currentNode = currentNode->parent;
    }
    if(printPath) {
        system("clear");
        print();
    }
    return true;
}

void NodeField::markPath(const int startX, const int startY, const int endX, const int endY, const bool printPath) {
    Node *startNode = findNode(startX, startY);
    Node *endNode = findNode(endX, endY);
    startNode->isStart = true;
    endNode->isEnd = true;
    list<Node *> openList;
    list<Node *> closedList;
    openList.push_back(startNode);

    while (!openList.empty()) {
        Node *currentNode = *min_element(openList.begin(), openList.end(),
                                         [](Node *a, Node *b) { return a->f < b->f; });
        currentNode->isCurrent = true;
        if (currentNode == endNode) {
            return;
        }

        openList.remove(currentNode);
        closedList.push_back(currentNode);
        currentNode->isOpen = false;
        currentNode->isClosed = true;

        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if ((dx == 0 && dy == 0) || (abs(dx) + abs(dy) == 2)) continue;
                int neighborX = currentNode->x + dx;
                int neighborY = currentNode->y + dy;

                if (neighborX < 0 || neighborX >= width || neighborY < 0 || neighborY >= height) {
                    continue;
                }

                Node *neighbor = findNode(neighborX, neighborY);

                if (neighbor->isObstacle ||
                    find(closedList.begin(), closedList.end(), neighbor) != closedList.end()) {
                    continue;
                }

                int tentativeG = currentNode->g + 1;

                bool inOpenList = find(openList.begin(), openList.end(), neighbor) != openList.end();

                if (!inOpenList || tentativeG < neighbor->g) {
                    neighbor->parent = currentNode;
                    neighbor->g = tentativeG;
                    neighbor->h = abs(neighbor->x - endNode->x) + abs(neighbor->y - endNode->y);
                    neighbor->f = neighbor->g + neighbor->h;

                    if (!inOpenList) {
                        openList.push_back(neighbor);
                        neighbor->isOpen = true;
                    }
                }
            }
        }

        currentNode->isCurrent = false;
        currentNode->isClosed = true;

        if (printPath) {
#ifdef _WIN32
            system("cls"); // For Windows
#else
            system("clear"); // For Unix/Linux
#endif
            print();
            this_thread::sleep_for(chrono::milliseconds(10));
        }

    }
    throw runtime_error("No path found");
}

Node *NodeField::findNode(const int x, const int y) {
    for (Node &node: nodes) {
        if (node.x == x && node.y == y) {
            return &node;
        }
    }
    throw invalid_argument("Node not found at position (" + to_string(x) + ", " + to_string(y) + ")");
}
