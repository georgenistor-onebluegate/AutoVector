#include <iostream>

#include "AutoVector.h"

int main()
{
    AutoVector<int> av;
    av.Initialize(6);

    for (int i = 0; i < 61; ++i) {
        av.Add(i);
    }

    av[55] = 99;


    std::cout << "Element count: " << av.size() << '\n';
    std::cout << "Buffer count: " << av.bufferCount() << '\n';
    std::cout << "Element at index 55: " << av[55] << "\n\n";

    av.Display();
    return 0;
}
