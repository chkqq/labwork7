#ifndef CMYARRAY_H
#define CMYARRAY_H

#include <stdexcept>
#include <algorithm>

template<typename T>
class CMyArray {
private:
    T* data; // Указатель на массив данных
    size_t size; // Размер массива
    size_t capacity; // Емкость массива

    void expandCapacity(size_t newCapacity);

public:
    CMyArray();
    CMyArray(const CMyArray& other);
    CMyArray(CMyArray&& other) noexcept;
    ~CMyArray();

    CMyArray& operator=(const CMyArray& other);
    CMyArray& operator=(CMyArray&& other) noexcept;

    void Add(const T& element);
    void Add(T&& element);

    size_t Size() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void Resize(size_t newSize);
    void Clear();

    T* begin();
    const T* begin() const;

    T* end();
    const T* end() const;

    T* rbegin();
    const T* rbegin() const;

    T* rend();
    const T* rend() const;
};

#endif // CMYARRAY_H
