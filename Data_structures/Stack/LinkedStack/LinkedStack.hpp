#pragma once

#include "Node.hpp"
#include <stdexcept>
#include <limits>

template<typename T>
class LinkedStack {
    Node<T> *dummy_node;
    int capacity;
    int size;

    public:
        LinkedStack();
        ~LinkedStack();

        void push(T x);
        T pop();
        T top();

        int get_size();
        bool is_empty();
};