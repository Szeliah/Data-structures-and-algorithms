#pragma once

#include <stdexcept>
#include <limits>
#include "Node.hpp"

template<typename T>
class LinkedQueue {
    int size;
    int capacity;
    Node<T> *dummy_node_head;
    Node<T> *dummy_node_tail;

    public: 
        LinkedQueue();
        ~LinkedQueue();

        void push(T x);
        T pop();
        T peek();

        int get_size();
        bool is_empty();
};