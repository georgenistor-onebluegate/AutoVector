#ifndef AUTOVECTOR_TPP
#define AUTOVECTOR_TPP

#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
AutoVector<T>::AutoVector()
    : current_bufferSize(0),
    size_propagation(0),
    current_index(0),
    elements_total(0),
    custom_propagation_size(0),
    singleBuffer(true)
{
}

template <typename T>
void AutoVector<T>::Initialize(std::size_t size)
{
    buffers.clear();
    sizes.clear();

    current_bufferSize = size;
    current_index = 0;
    elements_total = 0;
    size_propagation = 0;
    singleBuffer = true;

    if (size == 0)
    {
        return;
    }

    buffers.push_back(std::make_unique<Buffer<T>>(size));
    sizes.push_back(size);
}

template <typename T>
void AutoVector<T>::ChangePropagationBySize(size_t size)
{
    custom_propagation_size = size;
}

template <typename T>
void AutoVector<T>::Add(const T& element)
{
    if (buffers.empty())
    {
        throw std::logic_error("Call Initialize() before Add()");
    }

    // The final buffer's allocated size is stored in sizes.back().
    const std::size_t last_buffer_size = sizes.back();

    if (current_index >= last_buffer_size)
    {
        // Keep the growth policy explicit: use the configured propagation
        // increment. If none has been configured, use the previous buffer
        // size so Add() can continue growing safely.
        const std::size_t increment =
            size_propagation != 0 ? size_propagation : last_buffer_size;

        if (increment == 0)
        {
            throw std::logic_error("Cannot grow a zero-sized buffer");
        }

        current_bufferSize = increment;

        //Create a new buffer by custom_propagation_size after calling ChangePropagationBySize
        //Set back default behavior by calling ChangePropagationBySize(0)
        size_t decide_propagation_size= custom_propagation_size > 0 ? custom_propagation_size : current_bufferSize;
        buffers.push_back(
            std::make_unique<Buffer<T>>(decide_propagation_size));
        sizes.push_back(decide_propagation_size);
        current_index = 0;
    }

    (*buffers.back())[current_index] = element;
    ++current_index;
    ++elements_total;
}

template <typename T>
void AutoVector<T>::addBuffer()
{
    if (current_bufferSize == 0)
    {
        throw std::logic_error(
            "Call Initialize() with a non-zero size before addBuffer()");
    }

    buffers.push_back(
        std::make_unique<Buffer<T>>(current_bufferSize));
    sizes.push_back(current_bufferSize);
}

template <typename T>
std::size_t AutoVector<T>::bufferCount() const
{
    return buffers.size();
}

template <typename T>
std::size_t AutoVector<T>::getBufferSize() const
{
    return current_bufferSize;
}

template <typename T>
std::size_t AutoVector<T>::size() const
{
    return elements_total;
}


template <typename T>
void AutoVector<T>::Display() const
{
    std::size_t bufferIndex = 0;

    for (const auto& bufferPtr : buffers)
    {
        const Buffer<T>& buffer = *bufferPtr;

        std::cout << "Buffer " << bufferIndex << ": ";

        for (std::size_t i = 0; i < buffer.size(); ++i)
        {
            std::cout << buffer[i] << ' ';
        }

        std::cout << '\n';
        ++bufferIndex;
    }
}


template <typename T>
T& AutoVector<T>::operator[](std::size_t index)
{
    if (index >= elements_total)
    {
        throw std::out_of_range("AutoVector index out of range");
    }

    std::size_t offset = 0;

    for (std::size_t i = 0; i < buffers.size(); ++i)
    {
        const std::size_t buffer_size = *std::next(sizes.begin(),
            static_cast<std::ptrdiff_t>(i));

        if (index - offset < buffer_size)
        {
            auto it = std::next(buffers.begin(),
                static_cast<std::ptrdiff_t>(i));
            return (**it)[index - offset];
        }

        offset += buffer_size;
    }

    throw std::out_of_range("AutoVector index out of range");
}

template <typename T>
const T& AutoVector<T>::operator[](std::size_t index) const
{
    if (index >= elements_total)
    {
        throw std::out_of_range("AutoVector index out of range");
    }

    std::size_t offset = 0;
    auto sizeIt = sizes.begin();

    for (auto it = buffers.begin(); it != buffers.end(); ++it, ++sizeIt)
    {
        const std::size_t buffer_size = *sizeIt;

        if (index - offset < buffer_size)
        {
            return (**it)[index - offset];
        }

        offset += buffer_size;
    }

    throw std::out_of_range("AutoVector index out of range");
}

#endif // AUTOVECTOR_TPP
