#pragma once
#include "Node.hpp"
#include "../AbstractList/AbstractList.hpp"
#include <ostream>
#include <stdexcept>

template<typename T>
class LinkedList : public AbstractList<T> {
    Node<T> *head;
    uint64_t size = 0;

    public:
        LinkedList();
        LinkedList(T x);
        ~LinkedList();

        void push_back(T x) override;
        T pop_back() override;

        void push_front(T x) override;
        T pop_front() override;
        
        bool is_empty() override;
        uint64_t get_size() override;
        void clear();

        int find(const T& x);
};

