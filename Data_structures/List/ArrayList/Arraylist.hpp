#pragma once
#include <ostream>
#include <stdexcept>
#include "../AbstractList/AbstractList.hpp"

template<typename T>
class ArrayList : public AbstractList<T> {
    T *array;
    int size;
    int capacity;
    void resize();

    public:
        ArrayList();
        ArrayList(int _capacity);
        ~ArrayList();
        
        void push_front(const T& x) override;
        T pop_front() override;

        void push_back(const T& x) override;
        T pop_back() override;

        bool is_empty() override;
        int get_size() override;
        int get_capacity();
        void clear();
        int find(const T& x);
        T erase(int index);

        void insert(int index, const T& x);
        int remove(T x);

        bool replace(T oldv, T newv);   
};