#include "DoublyLinkedList.hpp"

// Constructors and destructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(): head{nullptr}, tail{nullptr}, size{0} {}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T x){
    this->head = new Node<T>(x);
    this->tail = this->head;
    this->size++;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    DoublyLinkedList<T>::clear();
}


// Methods for appending to and removing elements from the end of the list
template<typename T>
void DoublyLinkedList<T>::push_back(T x){
    Node<T>* new_node = new Node<T>(x, nullptr, this->tail);

    if (is_empty()) {
        this->head = this->tail = new_node;
    } else {
        this->tail->next = new_node;
        this->tail = new_node;
    }

    this->size++;
}

template<typename T>
T DoublyLinkedList<T>::pop_back(){
    if (is_empty()){
        throw std::out_of_range("List is empty!");     
    }

    if (get_size() == 1) {
        T outcome = head->value;
        delete head;
        head = nullptr;
        tail = nullptr;
        this->size--;
        return outcome;
    }

    Node<T> *prev = tail->prev;
    T outcome = tail->value;
    delete tail;
    prev->next = nullptr;
    this->tail = prev;
    this->size--;
    return outcome;

}


// Methods for appending to and removing elements from the beggining of the list
template<typename T>
void DoublyLinkedList<T>::push_front(T x){
     Node<T>* new_node = new Node<T>(x, this->head, nullptr);

    if (is_empty()) {
        this->head = this->tail = new_node;
    } else {
        this->head->prev = new_node;
        this->head = new_node;
    }

    this->size++;

}

template<typename T>
T DoublyLinkedList<T>::pop_front(){
    if (is_empty()){
        throw std::out_of_range("List is empty!");
    }

    if (get_size() == 1) {
        T outcome = head->value;
        delete head;
        this->head = this->tail = nullptr;
        this->size--;
        return outcome;
    }

    T outcome = head->value;
    Node<T> *temp = head->next;
    delete this->head;
    this->head = temp;
    this->head->prev = nullptr;
    this->size--;
    return outcome;
}



// Utility methods
template<typename T>
bool DoublyLinkedList<T>::is_empty() { return this->size == 0; }

template<typename T>
uint64_t DoublyLinkedList<T>::get_size() { return this->size; };

// Clear method 
template<typename T>
void DoublyLinkedList<T>::clear(){
    Node<T> *to_remove = this->head;
    while (to_remove != nullptr) {
        Node<T>* next = to_remove->next;
        delete to_remove;
        to_remove = next;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}



// Method that finds a element in the list and returns number >= 0 or -1 if elemetn doesn't exist in the list
template<typename T>
int DoublyLinkedList<T>::find(const T& x){
    Node<T> *iter = this->head;
    int index = 0;
    while (iter != nullptr){
        if (iter->value == x) return index;
        ++index;
        iter = iter->next; 
    }
    return -1;
}