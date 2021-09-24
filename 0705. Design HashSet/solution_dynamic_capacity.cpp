// 仅仅作为尝试，性能不高
// 很多都没有考虑，如链表中元素的有序性、直接移动链表节点而不是复制值、bucket 的大小增长等问题
class MyHashSet {
public:
  /** Initialize your data structure here. */
  MyHashSet() : _buckets(8), _max_factor(1.f), _elem_size(0) { }
  
  void add(int key) {
    if (_check_max_factor())
      _rehash(_get_new_hash_size(_buckets.size()));
    std::size_t _insert_pos = _hasher(key) % _buckets.size();
    for (auto iter = _buckets[_insert_pos].begin(); iter != _buckets[_insert_pos].end(); ++iter) {
      if (*iter == key)
        return;
    }
    _buckets[_insert_pos].push_back(key);
    ++_elem_size;
  }
  
  void remove(int key) {
    std::size_t _insert_pos = _hasher(key) % _buckets.size();
    for (auto iter = _buckets[_insert_pos].begin(); iter != _buckets[_insert_pos].end(); ++iter) {
      if (*iter == key) {
        _buckets[_insert_pos].erase(iter);
        --_elem_size;
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
  float _max_factor;
  std::size_t _elem_size;
  std::hash<int> _hasher;

  bool _check_max_factor() const {
    return static_cast<float>(_elem_size + 1) / static_cast<float>(_buckets.size()) > _max_factor;
  }

  std::size_t _get_new_hash_size(std::size_t old) const {
    if (old < 512)
      return old * 8;
    return old * 2;
  }

  void _rehash(std::size_t _new_bucket_size) {
    std::size_t _old_bucket_size = _buckets.size();
    _buckets.resize(_new_bucket_size);
    for (std::size_t i = 0; i < _old_bucket_size; ++i) {
      for (auto iter = _buckets[i].begin(); iter != _buckets[i].end();) {
        std::size_t _insert_pos = _hasher(*iter) % _new_bucket_size;
        if (_insert_pos != i) {
          _buckets[_insert_pos].push_back(*iter);
          iter = _buckets[i].erase(iter);
        } else
          ++iter;
      }
    }
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */