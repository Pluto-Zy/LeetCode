class MyHashSet {
public:
  /** Initialize your data structure here. */
  MyHashSet() : _buckets(769) { }
  
  void add(int key) {
    std::size_t _insert_pos = _hasher(key) % _buckets.size();
    for (auto iter = _buckets[_insert_pos].begin(); iter != _buckets[_insert_pos].end(); ++iter) {
      if (*iter == key)
        return;
    }
    _buckets[_insert_pos].push_back(key);
  }
  
  void remove(int key) {
    std::size_t _insert_pos = _hasher(key) % _buckets.size();
    for (auto iter = _buckets[_insert_pos].begin(); iter != _buckets[_insert_pos].end(); ++iter) {
      if (*iter == key) {
        _buckets[_insert_pos].erase(iter);
        return;
      }
    }
  }
  
  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    std::size_t _insert_pos = _hasher(key) % _buckets.size();
    for (auto iter = _buckets[_insert_pos].begin(); iter != _buckets[_insert_pos].end(); ++iter) {
      if (*iter == key) {
        return true;
      }
    }
    return false;
  }
private:
  std::vector<std::list<int>> _buckets;
  std::hash<int> _hasher;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */