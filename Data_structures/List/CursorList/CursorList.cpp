#include "CursorList.hpp"

template<typename T>
CursorList<T>::CursorList(int _capacity): capacity{_capacity}, size{0}, head{-1}, tail{-1}, free{0}  {
    this->nodes = new Node[this->capacity];
}


template<typename T>
CursorList<T>::~CursorList() {
    delete[] this->nodes;
}


template<typename T>
void CursorList<T>::push_front(const T& x) {
    
}


template<typename T>
T CursorList<T>::pop_front() {

}


template<typename T>
void CursorList<T>::push_back(const T& x) {

}


template<typename T>
T CursorList<T>::pop_back() {

}


template<typename T>
int CursorList<T>::get_size() {

}


template<typename T>
bool CursorList<T>::is_empty() {

}


template<typename T>
void CursorList<T>::clear() {

}


template<typename T>
int CursorList<T>::find(T x) {

}


template<typename T>
T CursorList<T>::erase(int idx) {

}


template<typename T>
void CursorList<T>::insert(int idx, T x) {

}


template<typename T>
int CursorList<T>::remove(T x) {

}


template<typename T>
int CursorList<T>::allocate() {

}


template<typename T>
void CursorList<T>::deallocate(int idx) {

}
