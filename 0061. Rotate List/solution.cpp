/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head)
        return nullptr;
      int list_length = 0;
      ListNode* next_k = head;
      for (int i = 0; i < k && next_k; ++i, ++list_length, next_k = next_k->next)
        ;
      if (!next_k) {
        k %= list_length;
        if (k == 0)
          return head;
        next_k = head;
        for (int i = 0; i < k && next_k; ++i, next_k = next_k->next)
          ;
      }
      ListNode* cur = head;
      while (next_k->next) {
        cur = cur->next;
        next_k = next_k->next;
      }
      next_k->next = head;
      ListNode* new_head = cur->next;
      cur->next = nullptr;
      return new_head;
    }
};