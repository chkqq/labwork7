#include "CMyArray.h"

template<typename T>
CMyArray<T>::CMyArray() : data(nullptr), size(0), capacity(0) {}

template<typename T>
CMyArray<T>::CMyArray(const CMyArray& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
CMyArray<T>::CMyArray(CMyArray&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template<typename T>
CMyArray<T>::~CMyArray() {
    delete[] data;
}

template<typename T>
CMyArray<T>& CMyArray<T>::operator=(const CMyArray& other) {
    if (this != &other) {
        T* newData = new T[other.capacity];
        for (size_t i = 0; i < other.size; i++) {
            newData[i] = other.data[i];
        }

        delete[] data;
        data = newData;
        size = other.size;
        capacity = other.capacity;
    }
    return *this;
}

template<typename T>
CMyArray<T>& CMyArray<T>::operator=(CMyArray&& other) noexcept {
    if (this != &other) {
        delete[] data;

        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template<typename T>
void CMyArray<T>::Add(const T& element) {
    if (size == capacity) {
        expandCapacity(capacity == 0 ? 1 : capacity * 2);
    }
    data[size] = element;
    size++;
}

template<typename T>
void CMyArray<T>::Add(T&& element) {
    if (size == capacity) {
        expandCapacity(capacity == 0 ? 1 : capacity * 2);
    }
    data[size] = std::move(element);
    size++;
}

template<typename T>
size_t CMyArray<T>::Size() const {
    return size;
}

template<typename T>
T& CMyArray<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T& CMyArray<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
void CMyArray<T>::Resize(size_t newSize) {
    if (newSize > capacity) {
        expandCapacity(newSize);
    }
    if (newSize > size) {
        for (size_t i = size; i < newSize; i++) {
            data[i] = T(); // Инициализация по умолчанию
        }
    }
    size = newSize;
}

template<typename T>
void CMyArray<T>::Clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
void CMyArray<T>::expandCapacity(size_t newCapacity) {
    if (newCapacity > capacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; i++) {
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}

template<typename T>
T* CMyArray<T>::begin() {
    return data;
}

template<typename T>
const T* CMyArray<T>::begin() const {
    return data;
}

template<typename T>
T* CMyArray<T>::end() {
    return data + size;
}

template<typename T>
const T* CMyArray<T>::end() const {
    return data + size;
}

template<typename T>
T* CMyArray<T>::rbegin() {
    return data + size - 1;
}

template<typename T>
const T* CMyArray<T>::rbegin() const {
    return data + size - 1;
}

template<typename T>
T* CMyArray<T>::rend() {
    return data - 1;
}

template<typename T>
const T* CMyArray<T>::rend() const {
    return data - 1;
}
