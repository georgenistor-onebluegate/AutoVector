//
// Created by george on 26.10.2026.
//

template <typename T>
Buffer<T>::Buffer(std::size_t size)
    : bufferSize(size),
      data(std::make_unique<T[]>(size))
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
    return data[index];
}

template <typename T>
const T& Buffer<T>::operator[](std::size_t index) const
{
    return data[index];
}