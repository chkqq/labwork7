#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class CMyStack {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);

public:
    CMyStack();
    ~CMyStack() noexcept;
    CMyStack(const CMyStack& other);
    CMyStack(CMyStack&& other) noexcept;
    CMyStack& operator=(const CMyStack& other);
    CMyStack& operator=(CMyStack&& other) noexcept;

    void push(const T& item);
    void push(T&& item);
    void pop();
    const T& top() const;
    bool is_empty() const;
};
