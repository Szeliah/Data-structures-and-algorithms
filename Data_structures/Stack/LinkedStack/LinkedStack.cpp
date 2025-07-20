#include "LinkedStack.hpp"

template<typename T>
LinkedStack<T>::LinkedStack(): capacity{8}, size{0} {
    this->dummy_node = new Node<T>;
    this->dummy_node->next = this->dummy_node;
}

template<typename T>
LinkedStack<T>::~LinkedStack() {
    Node<T> *to_remove = this->dummy_node->next;

    while (to_remove != this->dummy_node) {
        Node<T> *temp = to_remove->next;
        delete to_remove;
        to_remove = temp;
    }
}

template< typename T>
void LinkedStack<T>::push(T x) {
    if (this->size == this->capacity) {
        if (this->capacity == std::numeric_limits<int>::max()) {
            throw std::out_of_range("Stack overflow");
        }

        this->capacity *= 2;
    }

    Node<T> *new_node = new Node<T>(x, this->dummy_node->next);
    this->dummy_node->next = new_node;
    this->size++;
}

template<typename T>
T LinkedStack<T>::pop() {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }

    T result = this->dummy_node->next->value;
    Node<T> *to_remove = this->dummy_node->next;
    this->dummy_node->next = to_remove->next;
    delete to_remove;
    this->size--;
    return result;
}

template<typename T>
T LinkedStack<T>::top() {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }

    return this->dummy_node->next->value;
}

template<typename T>
int LinkedStack<T>::get_size() { return this->size; }

template<typename T>
bool LinkedStack<T>::is_empty() { return this->size == 0; }