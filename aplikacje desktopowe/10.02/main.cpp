#include <iostream>

struct Node {
    int data;
    Node *next;
};

// Now returns a pointer to Node
Node *initList(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void appendElement(Node *head, const int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    Node *tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void pushElement(Node *&head, const int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void deleteLastElement(Node *&head) {
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node *tmp = head;
    while (tmp->next->next != nullptr) {
        tmp = tmp->next;
    }
}

void printList(const Node *head) {
    const Node *tmp = head;
    while (tmp != nullptr) {
        std::cout << tmp->data;
        if (tmp->next != nullptr)
            std::cout << ", ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

int main() {
    int data = 1;
    Node *list = initList(data);
    appendElement(list, 2);
    appendElement(list, 3);
    pushElement(list, 0);
    deleteLastElement(list);
    printList(list);
    return 0;
}
