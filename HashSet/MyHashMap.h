class MyHashMap
{
  public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        for (int i = 0; i <= 10000; ++i)
        {
            map[i] = nullptr;
        }
    }

    /** value will always be positive. */
    void put(int key, int value)
    {
        int h_key = key % 10000;
        if (map[h_key] == nullptr)
        {
            map[h_key] = new int[100];
        }
        map[h_key][key / 10000] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        return map[key % 10000][key / 10000];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
    }

  private:
    int *map[10000] = {0};
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */