#include <vector>
#include <algorithm>
#define amount 10000
using namespace std;
class MyHashMap
{
public:
  /** Initialize your data structure here. */
  MyHashMap() { map.resize(amount); }

  /** value will always be positive. */
  void put(int key, int value)
  {
    int k = key;
    if (k < 0)
      k = -k;
    auto &row = map[k % amount];
    auto itor = find(row, key);
    if (itor == row.end())
    {
      row.push_back(make_pair(key, value));
    }
    else
    {
      itor->second = value;
    }
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
*contains no mapping for the key */
  int get(int key)
  {
    int k = key;
    if (k < 0)
      k = -k;
    auto &row = map[k % amount];
    auto itor = find(row, key);
    if (itor == row.end())
    {
      return -1;
    }
    else
    {
      return itor->second;
    }
  }

  /** Removes the mapping of the specified value key if this map contains a
*mapping for the key */
  void remove(int key)
  {
    int k = key;
    if (k < 0)
      k = -k;
    auto &row = map[k % amount];
    auto itor = find(row, key);
    if (itor != row.end())
    {
      row.erase(itor);
    }
  }

private:
  typedef pair<int, int> k_v;
  vector<vector<k_v>> map;

  vector<k_v>::iterator find(vector<k_v> &row, int key)
  { //迭代器不能被引用？
    for (auto it = row.begin(); it != row.end(); ++it)
    {
      if (it->first == key)
        return it;
    }
    return row.end();
  }
};

class MyHashSet
{
public:
  /** Initialize your data structure here. */
  MyHashSet() { table.resize(10000); }

  void add(int key)
  {
    int k = key;
    if (k < 0)
      k = -k;
    row_ &row = table[k % 10000];
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
    int k = key;
    if (k < 0)
      k = -k;
    row_ &row = table[k % 10000];
    auto itor = find(row.begin(), row.end(), key);
    if (itor != row.end())
    {
      row.erase(itor);
    }
  }

  /** Returns true if this set did not already contain the specified element */
  bool contains(int key)
  {
    int k = key;
    if (k < 0)
      k = -k;
    row_ &row = table[k % 10000];
    if (find(row.begin(), row.end(), key) == row.end())
      return false;
    else
      return true;
  }

private:
  typedef vector<int> row_;
  vector<row_> table;
};

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    MyHashMap mmp;
    for (int num : nums)
    {
      int old = mmp.get(num);
      if (old > 0)
      {
        mmp.put(num, old + 1);
      }
      else
      {
        mmp.put(num, 1);
      }
    }
    int ans = 0;
    for (int num : nums)
    {
      if (mmp.get(num) == 1)
        ans = num;
    }
    return ans;
  }

  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    MyHashSet op;
    MyHashSet res;
    vector<int> ans;

    for (int num : nums1)
    {
      op.add(num);
    }
    for (int num : nums2)
    {
      if (op.contains(num))
      {
        if (!res.contains(num))
        {
          ans.push_back(num);
          res.add(num);
        }
      }
    }
    return ans;
  }

  bool isHappy(int n)
  {
    MyHashSet mhs;
    while (n != 1)
    {
      int bits_suqre = 0;
      while (n != 0)
      {
        bits_suqre += (n % 10) * (n % 10);
        n /= 10;
      }
      n = bits_suqre;
      if (!mhs.contains(bits_suqre))
        mhs.add(bits_suqre);
      else
        return false;
    }
    return true;
  }

  vector<int> twoSum(vector<int> &nums, int target)
  {
    MyHashMap map;
    for (int i = 0; i < nums.size(); ++i)
    {
      map.put(nums[i], i);
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i)
    {
      int res1 = map.get(target - nums[i]);
      if (res1 != -1 && res1 != i)
      {
        res.push_back(i);
        res.push_back(res1);
        break;
      }
    }

    return res;
  }
};