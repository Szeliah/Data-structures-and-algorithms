#include "ArrayList.hpp"

template<typename T>
void ArrayList<T>::resize() {
    this->capacity *= 2;
    T *new_array = new T[this->capacity];

    for (int i = 0; i < size; ++i){
        new_array[i] = array[i];
    } 

    delete[] array;
    array = new_array;
}

template<typename T>
ArrayList<T>::ArrayList(): size{0}, capacity{10} {
    this->array = new T[10];
}

template<typename T>
ArrayList<T>::ArrayList(int _capacity): size{0}, capacity{_capacity} {
    this->array = new T[_capacity];
}

template<typename T>
ArrayList<T>::~ArrayList(){
    delete[] array;
}

template<typename T>
void ArrayList<T>::push_front(const T& x){
    if (this->size == this->capacity){
        resize();
    }

    for (int i = size - 1; i > -1; --i){
        array[i + 1] = array[i];
    }

    array[0] = x;
    this->size++;
}
template<typename T>
T ArrayList<T>::pop_front(){
    if (is_empty()){
        throw std::out_of_range("List is empty");
    }

    T result = array[0];

    for (int i = 1; i < this->size; ++i) {
        array[i - 1] = array[i];
    }

    this->size--;
    return result;
}

template<typename T>
void ArrayList<T>::push_back(const T& x){
    if (this->size == this->capacity){
        resize();
    }

    array[this->size] = x;
    this->size++;
}

template<typename T>
T ArrayList<T>::pop_back(){
    if (is_empty()){
        throw std::out_of_range("List is empty");
    }

    T result = array[size - 1];
    this->size--;
    return result;
}

template<typename T>
bool ArrayList<T>::is_empty() { return this->size == 0; }

template<typename T>
int ArrayList<T>::get_size() { return this->size; }

template<typename T>
int ArrayList<T>::get_capacity() { return this->capacity; }

template<typename T>
void ArrayList<T>::clear(){
    this->size = 0;
}

template<typename T>
int ArrayList<T>::find(const T& x) {
    for (int i = 0; i < this->size; ++i) {
        if (array[i] == x) {
            return i;
        }
    } 
    
    return -1;
}

template<typename T>
T ArrayList<T>::erase(int index) {
    if (is_empty()){
        throw std::out_of_range("List is empty");
    }

    if (index > this->size - 1 || index < 0){
        throw std::out_of_range("The index is out of bounds");
    }

    T result = array[index];

    for (int i = index; i < this->size - 1; ++i) {
        array[i] = array[i + 1]; 
    }

    this->size--;
    return result;
}

template<typename T>
void ArrayList<T>::insert(int index, const T& x) {
    if (index > this->size - 1 || index < 0){
        throw std::out_of_range("The index is out of bounds");
    }

    if (this->size == this->capacity) {
        resize();
    }
    
    for (int i = size - 1; i >= index; --i){
        array[i + 1] = array[i];
    }

    array[index] = x;
    this->size++;

}

template<typename T>
int ArrayList<T>::remove(T x) {
    if (is_empty()){
        throw std::out_of_range("List is empty");
    } 

    int number_of_x = 0;

    for (int i = 0; i < this->size; ++i) {
        if (array[i] == x) {
            ++number_of_x;
            
            for (int j = i; j < this->size - 1; ++j) {
                array[j] = array[j + 1];
            }

            this->size--;
        }
    }

    return number_of_x;
}

template<typename T>
bool ArrayList<T>::replace(T old_val, T new_val) {
    for (int i = 0; i < this->size; ++i) {
        if (array[i] == old_val){
            array[i] = new_val;
            return true;
        }
    }

    return false;
} 