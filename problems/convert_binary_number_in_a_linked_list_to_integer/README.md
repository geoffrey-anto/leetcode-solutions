# Convert Binary Number In A Linked List To Integer

## Leetcode Link: [Convert Binary Number In A Linked List To Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)
### Language: C++

```cpp
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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int l=0;
        while(temp!=nullptr){
            temp=temp->next;
            l++;
        }
        ListNode* ans = head;
        int v=0;
        while(ans!=nullptr){
            v+=pow(2,--l)*ans->val;
            ans=ans->next;
        }
        return v;
    }
};```



