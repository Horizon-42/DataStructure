#include <iostream>
using namespace std;
template <class Item>
struct Node
{
public:
  Item item;
  Node *next;

  friend ostream &operator<<(ostream &os, const Node<Item> &node)
  {
    os << node.item;
    return os;
  }
};

template <class Item>
class Bag
{
public:
  typedef class BagIterator
  {
  private:
    Node<Item> *itor;

  public:
    BagIterator(Node<Item> *itor)
    {
      this->itor = itor;
    }

    bool operator!=(BagIterator &it)
    {
      return this->itor != it.itor;
    }

    bool operator!=(Node<Item> *const it)
    {
      return this->itor != it;
    }

    Node<Item> *operator++(int)
    {
      Node<Item> *old = this->itor;
      this->itor = itor->next;
      return old;
    }

    Node<Item> operator*()
    {
      return *itor;
    }
  } iterator;

  Bag();
  void add(Item item);
  bool isEmpty();
  int size();
  Node<Item> *begin();
  Node<Item> *end();
  void reverse();

  virtual ~Bag();

private:
  Node<Item> *first;
  int N;
};