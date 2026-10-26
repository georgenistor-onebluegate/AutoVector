//
// Created by george on 26.10.2026.
//

template <typename T>
AutoVector<T>::AutoVector()
    : current_bufferSize(0),
      size_propagation(0),
      current_index(0),
      singleBuffer(true)
{
}

template <typename T>
AutoVector<T>::~AutoVector() = default;

template <typename T>
void AutoVector<T>::Initialize(std::size_t size)
{
    current_bufferSize = size;

    buffers.emplace_back(size);
    sizes.push_back(size);
}

template <typename T>
void AutoVector<T>::Propagate(std::size_t buffer_size)
{
    size_propagation = buffer_size;

    if (singleBuffer)
    {
        current_bufferSize += buffer_size;
        singleBuffer = false;
    }

    buffers.emplace_back(current_bufferSize);
    sizes.push_back(current_bufferSize);
}

template <typename T>
void AutoVector<T>::Add(T element)
{
    auto it = std::prev(buffers.end());

    if (current_index < current_bufferSize)
    {
        (*it)[current_index++] = element;
    }
    else
    {
        current_bufferSize += size_propagation;

        Propagate(8);

        current_index = 0;

        it = std::prev(buffers.end());
        (*it)[current_index++] = element;
    }
}

template <typename T>
void AutoVector<T>::addBuffer()
{
    buffers.emplace_back(current_bufferSize);
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
void AutoVector<T>::Display() const
{
    std::size_t bufferIndex = 0;

    for (const auto& buffer : buffers)
    {
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
    std::size_t offset = 0;

    for (auto& buffer : buffers)
    {
        if (index - offset < buffer.size())
        {
            return buffer[index - offset];
        }

        offset += buffer.size();
    }

    throw std::out_of_range("AutoVector index out of range");
}

template <typename T>
const T& AutoVector<T>::operator[](std::size_t index) const
{
    std::size_t offset = 0;

    for (const auto& buffer : buffers)
    {
        if (index >= offset && index - offset < buffer.size())
        {
            return buffer[index - offset];
        }

        offset += buffer.size();
    }

    throw std::out_of_range("AutoVector index out of range");
}
