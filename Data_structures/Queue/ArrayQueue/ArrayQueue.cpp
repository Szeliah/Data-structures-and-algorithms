#include "ArrayQueue.hpp"

template<typename T>
ArrayQueue<T>::ArrayQueue(): capacity{2e6}, size{0}, head{0}, tail{0} {
    this->array = new T[this->capacity];
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] this->array;
}

template<typename T>
void ArrayQueue<T>::push(T x) {
    if (this->size == this->capacity) {
            throw std::out_of_range("Queue overflow");
    }

    this->array[(this->tail++) % this->capacity] = x; 
    this->size++;
}

template<typename T>
T ArrayQueue<T>::pop() {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }

    T result = this->array[this->head];
    this->head = (this->head++) % this->capacity
    this->size--;
    return result;
}

template<typename T>
T ArrayQueue<T>::peek() {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }

    T result = this->array[this->head];
    return result;
}

template<typename T>
int ArrayQueue<T>::get_size() { return this->size; }

template<typename T>
bool ArrayQueue<T>::is_empty() { return this->size == 0; }