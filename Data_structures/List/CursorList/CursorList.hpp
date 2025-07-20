#pragma once

#include "Node.hpp"
#include <stdexcept>


template<typename T>
class CursorList : public AbstractList<T> {
    Node<T> *nodes;
    int size;
    int capacity;
    int head;
    int tail;
    int free;

    public:
        CursorList(int _capacity = 5e6);
        ~CursorList();

        void push_front(const T& x) override;
        T pop_front() override;

        void push_back(const T& x) override;
        T pop_back() override;
        
        int get_size() override;
        bool is_empty() override;
        void clear();

        int find(T x);
        T erase(int idx);
        
        void insert(int idx, T x);
        int remove(T x);

        int allocate();
        void deallocate(int idx);
};