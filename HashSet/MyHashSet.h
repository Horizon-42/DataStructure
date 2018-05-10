#include <vector>
#include <algorithm>
using namespace std;

class MyHashSet
{
  public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        table.resize(10000);
    }

    void add(int key)
    {
        row_ &row = table[key % 10000];
        if (find(row.begin(), row.end(), key) == row.end())
        {
            row.push_back(key);
        }
        else
        {
            return;
        }
    }

    void remove(int key)
    {
        if (contains(key))
        {
            row_ &row = table[key % 10000];
            row.erase(find(row.begin(), row.end(), key));
        }
    }

    /** Returns true if this set did not already contain the specified element */
    bool contains(int key)
    {
        row_ &row = table[key % 10000];
        if (find(row.begin(), row.end(), key) == row.end())
            return false;
        else
            return true;
    }

  private:
    typedef vector<int> row_;
    vector<row_> table;

    // vector<int>::iterator get_index(int key, vector<int> &row)
    // {
    //     for (auto it = row.begin(); it != row.end(); ++it)
    //     {
    //         if (*it == key)
    //             return it;
    //     }
    //     return row.end();
    // }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */