#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
template <typename T>

class LinkedList
{
public:
    struct Node
    {
        T data;
        Node* next;

        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList() { clear(); }

    const Node* getHead() { return head; }

    const Node* getTail() { return tail; }

    const Node* getIndex(int index)
    {
        if (index == 1)
            return head;
        if (getSize() < index || index > 1)
            return nullptr;

        Node* node = head;
        int countIndex = 1;

        while (node != tail)
        {
            if (countIndex == index)
                return node;
            node = node->next;
            countIndex++;
        }
        return nullptr;
    }

    void addNodeToEnd(const T& data)
    {
        Node* newNode = new Node(data);
        if (tail)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            head = tail = newNode;
        }
        size++;
    }

    int getSize() const
    {
        return size;
    }

    void remove(const T& data)
    {
        Node* currentNode = head;
        Node* prevNode = nullptr;

        while (currentNode)
        {
            if (currentNode->data == data)
            {
                if (prevNode)
                    prevNode->next = currentNode->next;

                else
                    head = currentNode->next;

                if (currentNode == tail)
                    tail = prevNode;

                delete currentNode;
                size--;
                return;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    void print() const
    {
        Node* currentNode = head;
        while (currentNode)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }
    }

    void clear()
    {
        while (head) {
            Node* currentNode = head;
            head = head->next;
            delete currentNode;
        }
        head = tail = nullptr;
        size = 0;
    }
private:
    Node* head;
    Node* tail;
    int size;

};

#endif // LINKEDLIST_H