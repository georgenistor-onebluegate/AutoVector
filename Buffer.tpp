#ifndef BUFFER_TPP
#define BUFFER_TPP

#include <stdexcept>

template <typename T>
Buffer<T>::Buffer(std::size_t size)
    : bufferSize(size),
      data(size != 0 ? std::make_unique<T[]>(size) : nullptr)
{
}

template <typename T>
std::size_t Buffer<T>::size() const
{
    return bufferSize;
}

template <typename T>
T& Buffer<T>::operator[](std::size_t index)
{
    if (index >= bufferSize)
    {
        throw std::out_of_range("Buffer index out of range");
    }

    return data[index];
}

template <typename T>
const T& Buffer<T>::operator[](std::size_t index) const
{
    if (index >= bufferSize)
    {
        throw std::out_of_range("Buffer index out of range");
    }

    return data[index];
}

#endif // BUFFER_TPP
