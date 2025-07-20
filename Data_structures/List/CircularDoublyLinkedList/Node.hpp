#pragma once

template<typename T>
class Node {
    T value;
    Node<T> *next;
    Node<T> *prev;

    Node();
    Node(T _value);
    Node(T _value, Node *_next, Node *_prev);

    friend class DoublyLinkedList;
};

template<typename T>
Node<T>::Node(): next{nullptr}, prev{nullptr} {}  

template<typename T>
Node<T>::Node(T _value): value{_value}, next{nullptr}, prev{nullptr} {}

template<typename T>
Node<T>::Node(T _value, Node<T> *_next, Node<T> *_prev): value{_value}, next{_next}, prev{_prev} {}