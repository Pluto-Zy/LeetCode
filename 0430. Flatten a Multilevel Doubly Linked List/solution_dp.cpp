/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
  Node* flatten(Node* head) {
    flatten_child(head);
    return head;
  }
private:
  // 遍历时，如果某一个节点的 child 非空，则递归扁平化其 child 节点
  // 并返回 child 所指链表的尾节点
  // 随后修改尾节点指向
  Node* flatten_child(Node* head) {
    Node* prev = nullptr;
    while (head) {
      if (head->child) {
        Node* tail = flatten_child(head->child);
        tail->next = head->next;
        if (head->next)
          head->next->prev = tail;
        head->next = head->child;
        head->child->prev = head;
        head->child = nullptr;
        prev = tail;
        head = tail->next;
      } else {
        prev = head;
        head = head->next;
      }
    }
    return prev;
  }
};