# Linked List Cycle

## Leetcode Link: [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
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
    bool hasCycle(ListNode *head) {
         ListNode *slow = head, *fast = head;
    
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            return true;
    }
    
    return false;
    }
};```



