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
public:
  Node* copyRandomList(Node* head) {
    if (!head)
      return nullptr;
    // 在每个节点后复制一个新节点
    for (Node* cur = head; cur; cur = cur->next->next) {
      Node* temp = new Node(cur->val);
      temp->next = cur->next;
      cur->next = temp;
    }
    // 连接 random 指针
    for (Node* cur = head; cur; cur = cur->next->next) {
      cur->next->random = cur->random ? cur->random->next : nullptr;
    }
    // 剥离结果
    Node* result = new Node(0);
    for (Node* cur = head, *result_head = result; cur; cur = cur->next, result_head = result_head->next) {
      result_head->next = cur->next;
      cur->next = cur->next->next;
      result_head->next->next = nullptr;
    }
    return result->next;
  }
};