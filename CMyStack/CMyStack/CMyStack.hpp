#ifndef CMYSTACK_HPP
#define CMYSTACK_HPP

#include <stdexcept>
#include <utility>

template <typename T>
class CMyStack
{
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);
public:
    CMyStack();
    ~CMyStack();

    CMyStack(const CMyStack& other);
    CMyStack& operator=(const CMyStack& other);

    CMyStack(CMyStack&& other) noexcept;
    CMyStack& operator=(CMyStack&& other) noexcept;

    void push(const T& element);
    void push(T&& element);
    void pop();
    const T& top() const;
    bool is_empty() const;
    void Clear();

};

template <typename T>
CMyStack<T>::CMyStack() : data(nullptr), capacity(0), size(0) {}

template <typename T>
CMyStack<T>::~CMyStack()
{
    delete[] data;
}

template <typename T>
CMyStack<T>::CMyStack(const CMyStack& other) : data(nullptr), capacity(0), size(0)
{
    if (other.size > 0)
    {
        data = new T[other.capacity];
        capacity = other.capacity;
        size = other.size;
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }
    }
}

template <typename T>
CMyStack<T>& CMyStack<T>::operator=(const CMyStack& other) 
{
    if (this == &other) return *this;

    CMyStack temp(other);
    std::swap(data, temp.data);
    std::swap(capacity, temp.capacity);
    std::swap(size, temp.size);

    return *this;
}

template <typename T>
CMyStack<T>::CMyStack(CMyStack&& other) noexcept : data(other.data), capacity(other.capacity), size(other.size)
{
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

template <typename T>
CMyStack<T>& CMyStack<T>::operator=(CMyStack&& other) noexcept
{
    if (this == &other) return *this;

    delete[] data;

    data = other.data;
    capacity = other.capacity;
    size = other.size;

    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;

    return *this;
}

template <typename T>
void CMyStack<T>::push(const T& element) 
{
    if (size == capacity) 
    {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = element;
}

template <typename T>
void CMyStack<T>::push(T&& element)
{
    if (size == capacity)
    {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = std::move(element);
}

template <typename T>
void CMyStack<T>::pop()
{
    if (is_empty()) 
    {
        throw std::underflow_error("Stack is empty");
    }
    --size;
}

template <typename T>
const T& CMyStack<T>::top() const
{
    if (is_empty()) 
    {
        throw std::underflow_error("Stack is empty");
    }
    return data[size - 1];
}

template <typename T>
bool CMyStack<T>::is_empty() const
{
    return size == 0;
}

template <typename T>
void CMyStack<T>::Clear() 
{
    size = 0;
}

template <typename T>
void CMyStack<T>::resize(size_t new_capacity)
{
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size; ++i)
    {
        new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

#endif
