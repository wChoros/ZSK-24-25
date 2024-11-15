#ifndef NODE_H
#define NODE_H

class Node {
public:
    int g = 0;
    int h = 0;
    int f = 0;
    bool isObstacle = false;
    bool isStart = false;
    bool isEnd = false;
    bool isPath = false;
    bool isCurrent = false;
    bool isOpen = false;
    bool isClosed = false;
    int x = 0;
    int y = 0;
    Node *parent = nullptr;
};

#endif // NODE_H
