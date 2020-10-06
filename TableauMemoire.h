#pragma once
#include <cstdio>
#include <string>
#include <stdexcept>
#include <algorithm>

template<typename T>
class TableauMemoire {
public:
    explicit TableauMemoire(size_t size);

    ~TableauMemoire();

    TableauMemoire<T>(const TableauMemoire<T> &other) = delete;

    TableauMemoire<T> &operator=(const TableauMemoire<T> &other) = delete;

    T &operator[](size_t index) { return read(index); }

    T &read(size_t index);

    void write(size_t index, const T &value);

    size_t size();

private:
    size_t _size;
    T *arrayPtr;
};

template<typename T>
TableauMemoire<T>::TableauMemoire(size_t size) {
    _size = size;
    arrayPtr = new T[_size];
    std::fill(arrayPtr, arrayPtr + _size, 0);
}

template<typename T>
TableauMemoire<T>::~TableauMemoire() {
    delete [] arrayPtr;
}

template<typename T>
T &TableauMemoire<T>::read(size_t index) {
    if (index < 0 || index >= _size)
        throw std::out_of_range("index " + std::to_string(index));

    return arrayPtr[index];
}

template<typename T>
void TableauMemoire<T>::write(size_t index, const T &value) {
    if (index < 0 || index >= _size)
        throw std::out_of_range("index " + std::to_string(index));

    arrayPtr[index] = value;
}

template<typename T>
size_t TableauMemoire<T>::size() {
    return _size;
}

