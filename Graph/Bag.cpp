#include <iostream>
#include "Bag.h"
using namespace std;

template <class Item>
Bag<Item>::Bag()
{
    this->N = 0;
    this->first = NULL;
}

template <class Item>
void Bag<Item>::add(Item item)
{
    Node<Item> *oldfirst = first;
    first = new Node<Item>;
    first->item = item;
    first->next = oldfirst;
    N++;
}

template <class Item>
bool Bag<Item>::isEmpty()
{
    return N == 0;
}

template <class Item>
int Bag<Item>::size()
{
    return N;
}

template <class Item>
Node<Item> *Bag<Item>::begin()
{
    return this->first;
}

template <class Item>
Node<Item> *Bag<Item>::end()
{
    return NULL;
}

template <class Item>
Bag<Item>::~Bag()
{
    Node<Item> *next;
    while (first != NULL)
    {
        next = first->next;
        delete[] first;
        first = next;
    }
}
