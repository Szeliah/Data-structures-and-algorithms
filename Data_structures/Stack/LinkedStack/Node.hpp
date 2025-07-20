#pragma once

template<typename T>
class Node {
    T value;
    Node<T> *next;

    Node();
    Node(T _value);
    Node(T _value, Node *_next);

    friend class LinkedStack;
};

template<typename T>
Node<T>::Node(): next{nullptr} {}  

template<typename T>
Node<T>::Node(T _value): value{_value}, next{nullptr} {}

template<typename T>
Node<T>::Node(T _value, Node<T> *_next): value{_value}, next{_next} {}