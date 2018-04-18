#include <iostream>
#include "Bag.cpp"
#include <vector>
using namespace std;

int main()
{
    Bag<int> a;
    for (int i = 0; i < 10; ++i)
    {
        a.add(i);
    }
    for (Bag<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}