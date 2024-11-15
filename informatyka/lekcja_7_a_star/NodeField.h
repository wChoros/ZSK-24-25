#ifndef NODEFIELD_H
#define NODEFIELD_H

#include <list>
#include <string>
#include "Node.h"

class NodeField {
public:
    std::list<Node> nodes;
    int width = 0;
    int height = 0;

    NodeField(const std::string &filepath);
    NodeField(int width, int height);

    void addObstacles(float probability_percentage);
    void print();
    bool findPath(int startX, int startY, int endX, int endY, bool printPath);

private:
    void markPath(int startX, int startY, int endX, int endY, bool printPath);

    char obstacle = '*';
    std::string start = "\033[1;32mS\033[1;0m";
    std::string end = "\033[1;34mE\033[1;0m";
    std::string path = "\033[1;36m.\033[1;0m";
    std::string open = "\033[1;33mO\033[1;0m";
    std::string closed = "\033[1;31mC\033[1;0m";
    std::string current = "\033[1;35mX\033[1;0m";
    char empty = ' ';

    Node *findNode(int x, int y);
};

#endif // NODEFIELD_H
