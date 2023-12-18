// Dans Array.hpp
#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array &rhs);
    Array &operator=(const Array &src);
    T &operator[](unsigned int index);
    ~Array();

    size_t getSize() const;

private:
    T *_array;
    size_t _size;
};

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index is out of range");
    }
    return _array[index];
}

template <typename T>
Array<T>::Array() : _array(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) {
    if (n > 0) {
        _array = new T[n];
        _size = n;
    } else {
        _array = 0;
        _size = 0;
    }
}

template <typename T>
Array<T>::Array(const Array &rhs) : _size(rhs._size) {
    _array = new T[_size];
    for (size_t i = 0; i < _size; i++)
        _array[i] = rhs._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src) {
    if (this != &src) {
        delete[] _array;
        _size = src._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _array[i] = src._array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
size_t Array<T>::getSize() const {
    return _size;
}
