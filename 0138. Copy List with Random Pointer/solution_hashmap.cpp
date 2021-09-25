/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  std::unordered_map<Node*, Node*> _node_map;
public:
  Node* copyRandomList(Node* head) {
    return _copy_from_node(head);
  }

  Node* _copy_from_node(Node* head) {
    if (!head)
      return nullptr;
    Node* result = _get_node(head);
    result->random = _get_node(head->random);
    head = head->next;
    for (Node* cur = result; head; head = head->next, cur = cur->next) {
      cur->next = _get_node(head);
      cur->next->random = _get_node(head->random);
    }
    return result;
  }

  Node* _get_node(Node* src) {
    if (!src)
      return nullptr;
    if (auto iter = _node_map.find(src); iter != _node_map.end())
      return iter->second;
    Node* temp = new Node(src->val);
    _node_map[src] = temp;
    return temp;
  }
};