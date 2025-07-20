#pragma once
#include "Node.hpp"
#include "../AbstractList/AbstractList.hpp"
#include <ostream>
#include <stdexcept>

template<typename T>
class CircularDoublyLinkedList : public AbstractList<T> {
    Node<T> *dummy_node;
    uint64_t size = 0;

    public:
        CircularDoublyLinkedList();
        CircularDoublyLinkedList(T x);
        ~CircularDoublyLinkedList();

        void push_front(const T& x) override;
        T pop_front() override ;

        void push_back(const T& x) override ;
        T pop_back() override ;

        bool is_empty() override ;
        uint64_t get_size() override ;
        void clear();
        int find(const T& x);
        T erase(int index);

        void insert(int index, const T& x);
        int remove(T x);

        bool replace(T oldv, T newv);    
};

