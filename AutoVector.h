#ifndef AUTOVECTOR_H
#define AUTOVECTOR_H

#include <cstddef>
#include <list>
#include <iterator>
#include <memory>

#include "Buffer.h"

template <typename T>
class AutoVector
{
private:
    std::list<std::unique_ptr<Buffer<T>>> buffers;

    // Sizes of each allocated buffer, in the same order as buffers.
    std::list<std::size_t> sizes;

    std::size_t current_bufferSize;
    std::size_t size_propagation;
    std::size_t current_index;
    std::size_t elements_total;
    bool singleBuffer;

public:
    AutoVector();
    ~AutoVector() = default;

    // Create the first buffer. Calling Initialize again resets the contents.
    void Initialize(std::size_t size);

    // Append an element to the AutoVector.
    void Add(const T& element);

    void addBuffer();

    std::size_t bufferCount() const;
    std::size_t getBufferSize() const;
    std::size_t size() const;

    void Display() const;

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
};

#include "AutoVector.tpp"

#endif // AUTOVECTOR_H
