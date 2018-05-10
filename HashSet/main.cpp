#include "MyHashSet.h"
#include <iostream>

using namespace std;

int main()
{
    MyHashSet set;
    set.add(1);
    set.add(2);
    cout << set.contains(1) << endl;
    cout << set.contains(3) << endl;
    set.add(2);
    cout << set.contains(2) << endl;
    set.remove(2);
    cout << set.contains(2) << endl;
}