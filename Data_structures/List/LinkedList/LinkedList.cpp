#include "LinkedList.hpp"

// Constructors and destructor
template<typename T>
LinkedList<T>::LinkedList(): head{nullptr}, size{0} {}

template<typename T>
LinkedList<T>::LinkedList(T x){
    this->head = new Node<T>(x);
    this->size++;
}

template<typename T>
LinkedList<T>::~LinkedList(){
    LinkedList<T>::clear();
}


// Methods for appending to and removing elements from the end of the list
template<typename T>
void LinkedList<T>::push_back(T x){
    if (get_size() == 0){
        this->head = new Node<T>(x);
    }
    else {
        Node<T> *node = this->head;
        while (node->next != nullptr){
            node = node->next;
        }
        node->next = new Node<T>(x);
    }  
    this->size++; 
}

template<typename T>
T LinkedList<T>::pop_back(){
    if (is_empty()){
        throw std::out_of_range("List is empty!");     
    }

   if (LinkedList<T>::get_size() == 1) {
        T outcome = head->value;
        delete head;
        head = nullptr;
        this->size--;
        return outcome;
    }

    Node<T> *node = this->head;
    Node<T> *prev = this->head;

    while(node->next != nullptr){
        prev = node;
        node = node->next;
    }

    T outcome = node->value;
    prev->next = nullptr;
    delete node;
    this->size--;
    return outcome;
}



// Methods for appending to and removing elements from the beggining of the list
template<typename T>
void LinkedList<T>::push_front(T x){
    Node<T> *new_node = new Node<T>(x);
    Node<T> *temp = this->head;
    this->head = new_node;
    head->next = temp; 
    this->size++;
}

template<typename T>
T LinkedList<T>::pop_front(){
    if (is_empty()){
        throw std::out_of_range("List is empty!");
    }

    T outcome = head->value;
    Node<T> *temp = head->next;
    delete this->head;
    this->head = temp;
    this->size--;
    return outcome;
}



// Utility mehtods
template<typename T>
bool LinkedList<T>::is_empty() { return this->size == 0; }

template<typename T>
uint64_t LinkedList<T>::get_size() { return this->size; };

// Clear method 
template<typename T>
void LinkedList<T>::clear(){
    Node<T> *to_remove = this->head;
    while (to_remove != nullptr) {
        Node<T>* next = to_remove->next;
        delete to_remove;
        to_remove = next;
    }
    this->head = nullptr;
    this->size = 0;
}



// Method that finds a element in the list and returns number >= 0 or -1 if elemetn doesn't exist in the list
template<typename T>
int LinkedList<T>::find(const T& x){
    Node<T> *iter = this->head;
    int index = 0;
    while (iter != nullptr){
        if (iter->value == x) return index;
        ++index;
        iter = iter->next; 
    }
    return -1;
}