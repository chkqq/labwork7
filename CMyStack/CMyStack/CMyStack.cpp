#include "CMyStack.h"

template<typename T>
CMyStack<T>::CMyStack() : data(new T[2]), capacity(2), size(0) {}

template<typename T>
CMyStack<T>::~CMyStack() noexcept {
    delete[] data;
}

template<typename T>
CMyStack<T>::CMyStack(const CMyStack& other)
    : data(new T[other.capacity]), capacity(other.capacity), size(other.size)
{
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
CMyStack<T>::CMyStack(CMyStack&& other) noexcept
    : data(other.data), capacity(other.capacity), size(other.size)
{
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

template<typename T>
CMyStack<T>& CMyStack<T>::operator=(const CMyStack& other) {
    if (this != &other) {
        CMyStack temp(other);
        std::swap(data, temp.data);
        std::swap(capacity, temp.capacity);
        std::swap(size, temp.size);
    }
    return *this;
}

template<typename T>
CMyStack<T>& CMyStack<T>::operator=(CMyStack&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        capacity = other.capacity;
        size = other.size;
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

template<typename T>
void CMyStack<T>::push(const T& item) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[size] = item;
    ++size;
}

template<typename T>
void CMyStack<T>::push(T&& item) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[size] = std::move(item);
    ++size;
}

template<typename T>
void CMyStack<T>::pop() {
    if (size == 0) {
        throw std::out_of_range("Stack underflow: trying to pop from empty stack");
    }
    --size;
}

template<typename T>
const T& CMyStack<T>::top() const {
    if (size == 0) {
        throw std::out_of_range("Stack is empty: trying to access top of empty stack");
    }
    return data[size - 1];
}

template<typename T>
bool CMyStack<T>::is_empty() const {
    return size == 0;
}

template<typename T>
void CMyStack<T>::resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}
