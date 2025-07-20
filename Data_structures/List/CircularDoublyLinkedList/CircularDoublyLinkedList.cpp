#include "CircularDoublyLinkedList.hpp"

// Constructors and destructor
template<typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(): size{0}{
    this->dummy_node = new Node<T>();

    this->dummy_node->prev = this->dummy_node;
    this->dummy_node->next = this->dummy_node;
}

template<typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(T x){ 
    this->dummy_node = new Node<T>();

    Node<T> *new_node = new Node<T>(x, this->dummy_node, this->dummy_node);
    this->dummy_node->prev = new_node;
    this->dummy_node->next = new_node;
    this->size++;
}

template<typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList(){
    CircularDoublyLinkedList<T>::clear();
    delete dummy_node;
}


// Methods for appending to and removing elements from the end of the list
template<typename T>
void CircularDoublyLinkedList<T>::push_back(const T& x){
    Node<T> *tail = this->dummy_node->prev;  
    Node<T> *new_node = new Node<T>(x, this->dummy_node, tail);

    tail->next = new_node;
    dummy_node->prev = new_node;
    this->size++;
}

template<typename T>
T CircularDoublyLinkedList<T>::pop_back(){
    if (is_empty()){
        throw std::out_of_range("List is empty");     
    }

    Node<T> *tail = this->dummy_node->prev;
    T result = tail->value;
    this->dummy_node->prev = tail->prev;
    tail->prev->next = this->dummy_node;
    delete tail;
    this->size--;
    return result;
}


// Methods for appending to and removing elements from the beggining of the list
template<typename T>
void CircularDoublyLinkedList<T>::push_front(const T& x){
    Node<T> *head = this->dummy_node->next;
    Node<T> *new_node = new Node<T>(x, head, this->dummy_node);

    head->prev = new_node;
    this->dummy_node->next = new_node;
    this->size++;
}

template<typename T>
T CircularDoublyLinkedList<T>::pop_front(){
    if (is_empty()){
        throw std::out_of_range("List is empty!");
    }

    Node<T> *head = this->dummy_node->next;
    T result = head->value;
    this->dummy_node->next = head->next;
    head->next->prev = this->dummy_node;
    delete head;
    this->size--;
    return result;
}



// Utility methods
template<typename T>
bool CircularDoublyLinkedList<T>::is_empty() { return this->size == 0; }

template<typename T>
uint64_t CircularDoublyLinkedList<T>::get_size() { return this->size; }

// Clear method 
template<typename T>
void CircularDoublyLinkedList<T>::clear(){
    Node<T> *to_remove = this->dummy_node->next;

    while(to_remove != this->dummy_node){
        Node<T> *temp = to_remove->next;
        delete to_remove;
        to_remove = temp;
    }
    
    this->dummy_node->next = dummy_node;
    this->dummy_node->prev = dummy_node;
    this->size = 0;
}



// Method that finds a element in the list and returns number >= 0 or -1 if elemetn doesn't exist in the list
template<typename T>
int CircularDoublyLinkedList<T>::find(const T& x){
    Node<T> *iter = this->dummy_node->next;
    int index = 0;
    
    while (iter != this->dummy_node){
        
        if (iter->value == x){
            return index;
        }
        iter = iter->next;
        ++index;
    }
    
    return -1;
}

//Removes the node at the specified index and returns its valu (throws if index is out of bounds)
template<typename T>
T CircularDoublyLinkedList<T>::erase(int index){
    if (is_empty()){
        throw std::out_of_range("List is empty");
    }

    if (index > this->size - 1){
        throw std::out_of_range("The index is out of bounds");
    }

    Node<T> *iter = this->dummy_node->next;
    for (int i = 0; i < index; ++i){
            iter = iter->next;
    }

    T result = iter->value;
    iter->prev->next = iter->next;
    iter->next->prev = iter->prev;
    delete iter;
    this->size--;
    return result;
}


// Inserts value x before the element at index
template<typename T>
void CircularDoublyLinkedList<T>::insert(int index, const T& x){
    if (index > this->size - 1){
        throw std::out_of_range("The index is out of bounds");
    }
     
    Node<T> *iter = this->dummy_node->next;
    for (int i = 0; i < index; ++i){
            iter = iter->next;
    }

    Node<T> *new_node = new Node<T>(x, iter, iter->prev);
    iter->prev->next = new_node;
    iter->prev = new_node;
    this->size++;
}


// Removes all nodes with value x, returns how many were removed 
template<typename T>
int CircularDoublyLinkedList<T>::remove(T x){
    Node<T> *iter = this->dummy_node->next;
    int number_of_x = 0;
    
    while (iter != this->dummy_node){
        Node<T> *temp = iter;
        iter = iter->next;
        if (temp->value == x){
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            ++number_of_x;
            this->size--;
            delete temp;
        }

    }
    
    return number_of_x;
}

// Method that replace old value with new one
template<typename T>
bool CircularDoublyLinkedList<T>::replace(T old_val, T new_val){
    Node<T> *iter = this->dummy_node->next;
    
    while (iter != this->dummy_node){
        if (iter->value == old_val){
            iter->value = new_val;
            return true;
        }
        iter = iter->next;
    }

    return false;
}


