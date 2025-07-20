#pragma once

template<typename T>
class AbstractList {
    public:
        virtual ~AbstractList() = default;
        virtual void push_back(const T& x) = 0;
        virtual T pop_back() = 0;
        virtual void push_front(const T& x) = 0;
        virtual T pop_front() = 0;
        virtual bool is_empty() = 0;
        virtual int get_size() = 0;
};