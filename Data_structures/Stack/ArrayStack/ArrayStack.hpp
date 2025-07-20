#pragma once

#include <stdexcept>
#include <limits>

template<typename T>
class ArrayStack {
    int capacity;
    int size;
    T *array;
    void resize();

    public:
        ArrayStack();
        ~ArrayStack();

        void push(T x);
        T pop();
        T top();

        int get_size();
        bool is_empty();
};