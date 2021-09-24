class MyHashMap {
public:
  /** Initialize your data structure here. */
  MyHashMap() : _buckets(769) { }
  
  /** value will always be non-negative. */
  void put(int key, int value) {
    std::size_t _insert_pos = _hasher(key) % _buckets.size();
    for (auto iter = _buckets[_insert_pos].begin(); iter != _buckets[_insert_pos].end(); ++iter) {
      if (iter->first == key) {
        iter->second = value;
        return;
      }
    }
    _buckets[_insert_pos].emplace_back(key, value);
  }
  
  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    std::size_t _insert_pos = _hasher(key) % _buckets.size();
    for (auto iter = _buckets[_insert_pos].begin(); iter != _buckets[_insert_pos].end(); ++iter) {
      if (iter->first == key) {
        return iter->second;
      }
    }
    return -1;
  }
  
  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    std::size_t _insert_pos = _hasher(key) % _buckets.size();
    for (auto iter = _buckets[_insert_pos].begin(); iter != _buckets[_insert_pos].end(); ++iter) {
      if (iter->first == key) {
        _buckets[_insert_pos].erase(iter);
        return;
      }
    }
  }
private:
  std::vector<std::list<std::pair<const int, int>>> _buckets;
  std::hash<int> _hasher;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */