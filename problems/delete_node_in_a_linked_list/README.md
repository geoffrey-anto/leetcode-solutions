# Delete Node In A Linked List

## Leetcode Link: [Delete Node In A Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)
### Language: C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* toDelete = node->next;
        node->next = node->next->next;
        delete toDelete;
    }
};```



