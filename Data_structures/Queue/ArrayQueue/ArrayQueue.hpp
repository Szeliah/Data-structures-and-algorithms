#pragma once

#include <stdexcept>
#include <limits>

template<typename T>
class ArrayQueue {
    int capacity;
    int size;
    int head;
    int tail;
    T *array;
    
    public:
        ArrayQueue();
        ~ArrayQueue();

        void push(T x);
        T pop();
        T peek();

        int get_size();
        bool is_empty();
};