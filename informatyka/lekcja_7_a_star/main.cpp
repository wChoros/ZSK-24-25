#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Node {
public:
    int g = 0;
    int h = 0;
    int f = 0;
    bool isObstacle = false;
    bool isStart = false;
    bool isEnd = false;
    bool isPath = false;
    int x = 0;
    int y = 0;
    Node *parent = nullptr;
};

class NodeField {
public:
    list<Node> nodes;
    int width = 0;
    int height = 0;

    NodeField(const string &filepath) {
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
                node.x = i;
                node.y = j;
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

    void print() {
        // Adjusted to check for changes in the x-coordinate
        int previousX = -1;
        for (Node &node: nodes) {
            if (node.x != previousX) {
                cout << endl;
            }
            if (node.isObstacle) {
                cout << obstacle;
            } else if (node.isEnd) {
                cout << end;
            } else if (node.isStart) {
                cout << start;
            } else if (node.isPath) {
                cout << path;
            } else {
                cout << empty;
            }
            previousX = node.x;
        }
        cout << endl;
    }

    void findPath(const int startX, const int startY, const int endX, const int endY) {
        markPath(startX, startY, endX, endY);
        Node *currentNode = findNode(endX, endY);
        while (currentNode->parent != nullptr && !currentNode->isStart) {
            currentNode->isPath = true;
            currentNode = currentNode->parent;
        }
    }

private:
    void markPath(const int startX, const int startY, const int endX, const int endY) {
        Node *startNode = findNode(startX, startY);
        Node *endNode = findNode(endX, endY);
        startNode->isStart = true;
        endNode->isEnd = true;
        list<Node *> openList;
        list<Node *> closedList;
        openList.push_back(startNode);

        while (!openList.empty()) {
            // Find the node with the lowest f value
            Node *currentNode = *min_element(openList.begin(), openList.end(),
                                             [](Node *a, Node *b) { return a->f < b->f; });

            if (currentNode == endNode) {
                // Path has been found
                return;
            }

            openList.remove(currentNode);
            closedList.push_back(currentNode);

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if ((i == 0 && j == 0) || (abs(i) + abs(j) == 2)) continue;
                    int neighborX = currentNode->x + i;
                    int neighborY = currentNode->y + j;

                    // Bounds checking
                    if (neighborX < 0 || neighborX >= height || neighborY < 0 || neighborY >= width) {
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
                        }
                    }
                }
            }
        }
        throw runtime_error("No path found");
    }

    char obstacle = '*';
    string start = "\033[1;32mS\033[1;0m";
    string end = "\033[1;31mE\033[1;0m";
    string path = "\033[1;36m.\033[1;0m";
    char empty = ' ';

    Node *findNode(const int x, const int y) {
        for (Node &node: nodes) {
            if (node.x == x && node.y == y) {
                return &node;
            }
        }
        throw invalid_argument("Node not found at position (" + to_string(x) + ", " + to_string(y) + ")");
    }
};

int main() {
    try {
        NodeField field("../field.txt"); // Adjusted file path
        field.findPath(1, 0, 24, 4); // Example start and end positions
        field.print(); // Display the field with the path
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
