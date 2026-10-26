#include <iostream>
#include "AutoVector.h"
using namespace std;


int main() {

    AutoVector<int> av;  // Each buffer contains 1024 integers
    av.Initialize(6);

    av.Add(0);
    av.Add(1);
    av.Add(2);
    av.Add(3);
    av.Add(4);
    av.Add(5);
    av.Add(6);
    av.Add(7);
    av.Add(8);
    av.Add(9);
    av.Add(10);
    av.Add(11);
    av.Add(12);
    av.Add(13);
    av.Add(14);
    av.Add(15);
    av.Add(16);
    av.Add(17);
    av.Add(18);
    av.Add(19);
    av.Add(20);
    av.Add(21);
    av.Add(22);
    av.Add(23);
    av.Add(24);
    av.Add(25);
    av.Add(26);
    av.Add(27);
    av.Add(28);
    av.Add(29);
    av.Add(30);
    av.Add(31);
    av.Add(32);
    av.Add(33);
    av.Add(34);
    av.Add(35);
    av.Add(36);
    av.Add(37);
    av.Add(38);
    av.Add(39);
    av.Add(40);
    av.Add(41);
    av.Add(42);
    av.Add(43);
    av.Add(44);
    av.Add(45);
    av.Add(46);
    av.Add(47);
    av.Add(48);
    av.Add(49);
    av.Add(50);
    av.Add(51);
    av.Add(52);
    av.Add(53);

    av[54]=54;
    av[55]=55;
    av[56]=56;

    av.Display();

    return 0;
}