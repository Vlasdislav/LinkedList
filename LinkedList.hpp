#pragma once

#include <vector>

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node() = default;

    Node(const T& val)
        : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void remove(T val) {
        if (!head) {
            return;
        }

        if (head->data == val) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next) {
            if (current->next->data == val) {
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    bool find(T val) {
        Node<T>* current = head;
        while (current) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    std::vector<T> to_vector() {
        std::vector<T> res;
        Node<T>* current = head;
        while (current) {
            res.emplace_back(current->data);
            current = current->next;
        }
        return res;
    }
};
