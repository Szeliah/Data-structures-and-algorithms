#include "ArrayStack.hpp"

template<typename T>
void ArrayStack<T>::resize() {
    this->capacity *= 2;
    T *new_array = new T[this->capacity];

    for (int i = 0; i < this->size; ++i) {
        new_array[i] = this->array[i];
    }

    delete[] this->array;
    this->array = new_array;
}

template<typename T>
ArrayStack<T>::ArrayStack(): capacity{8}, size{0} {
    this->array = new T[this->capacity];
}

template<typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] array;
}

template<typename T>
void ArrayStack<T>::push(T x) {
    if (this->size == this->capacity) {
        if (this->capacity == std::numeric_limits<int>::max()) {
            throw std::out_of_range("Stack overflow");
        }

        resize();
    }

    this->array[size] = x;
    this->size++;
}

template<typename T>
T ArrayStack<T>::pop() {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty"); 
    }

    T result= this->array[this->size - 1];
    this->size--;
    return result;
}

template<typename T>
T ArrayStack<T>::top() {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty"); 
    }

    T result= this->array[this->size - 1];
    return result;
}

template<typename T>
int ArrayStack<T>::get_size() { return this->size; }

template<typename T>
bool ArrayStack<T>::is_empty() { return this->size == 0; }