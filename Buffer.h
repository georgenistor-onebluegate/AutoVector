//
// Created by george on 26.10.2026.
//
#ifndef BUFFER_H
#define BUFFER_H

#include <cstddef>
#include <memory>

template <typename T>
class Buffer
{
    std::size_t bufferSize;
    std::unique_ptr<T[]> data;

public:
    explicit Buffer(std::size_t size);

    std::size_t size() const;

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
};

#include "Buffer.tpp"

#endif


