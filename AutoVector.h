//
// Created by george on 26.10.2026.
//

#pragma once
#include <cstddef>
#include <iterator>
#include <list>
#include "Buffer.h"

template <typename T>
class AutoVector
{
    std::list<Buffer<T>> buffers;
    std::size_t current_bufferSize, size_propagation;
    std::list<std::size_t> sizes;

    std::size_t current_index;
    bool singleBuffer;

public:
    AutoVector();

    ~AutoVector();

    void Initialize(std::size_t size);
    void Propagate(std::size_t buffer_size);
    void Add(T element);
    void addBuffer();

    std::size_t bufferCount() const;
    std::size_t getBufferSize() const;

    void Display() const;

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
};

#include "AutoVector.tpp"
