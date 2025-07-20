#include "LinkedQueue.hpp"

template<typename T>
LinkedQueue<T>::LinkedQueue(): size{0}, capacity{5e6} {
    this->dummy_node_head = new Node<T>();
    this->dummy_node_tail = new Node<T>();
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    while (this->dummy_node_head != nullptr) {
        Node<T> *temp = this->dummy_node_head->next;
        delete this->dummy_node_head;
        this->dummy_node_head = temp;
    }
}

template<typename T>
void LinkedQueue<T>::push(T x) {
    if (this->size == this->capacity) {
        throw std::out_of_range("Queue is full");
    }

    Node<T> new_node = new Node<T>(x, nullptr);
    
    if (this->dummy_node_head->next = nullptr) {
        this->dummy_node_head->next = new_node;
    }

    Node<T> *temp = this->dummy_node_tail->next;
    temp->next = new_node;
    this->dummy_node_tail = new_node;
    this->size++;
}

template<typename T>
T LinkedQueue<T>::pop() {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }

    T result = this->dummy_node_head->next->value;
    Node<T> *temp = this->dummy_node_head.next;
    this->dummy_node_head->next = temp->next;
    delete temp;
    this->size--;
    return result;
}

template<typename T>
T LinkedQueue<T>::peek() {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }

    T result = this->dummy_node_head->next->value;
    return result;
}

template<typename T>
int LinkedQueue<T>::get_size() { return this->size; }

template<typename T>
bool LinkedQueue<T>::is_empty() { return this->size == 0; }
