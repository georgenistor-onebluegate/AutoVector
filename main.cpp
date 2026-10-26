#include <iostream>

#include "AutoVector.h"

int main()
{
    AutoVector<int> av;
    av.Initialize(6);

    for (int i = 0; i < 50; ++i) {
        av.Add(i);
    }

    av.ChangePropagationBySize(5); //append just 5 new elements with each re-size

    for (int i = 50; i < 70; ++i) {
        av.Add(i);
    }

    av[55] = 99;

    av.ChangePropagationBySize(10); //append just 10 new elements with each re-size

    for (int i = 70; i <= 90; ++i) {
        av.Add(i);
    }

    for (int i = 91; i <= 100; ++i) {
        av.Add(i);
    }

    std::cout << "Element count: " << av.size() << '\n';
    std::cout << "Buffer count: " << av.bufferCount() << '\n';
    std::cout << "Element at index 55: " << av[55] << "\n\n";

    av.Display();
    return 0;
}
