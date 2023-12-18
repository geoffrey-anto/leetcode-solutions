# Maximum Twin Sum Of A Linked List

## Leetcode Link: [Maximum Twin Sum Of A Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)
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
    
    ListNode* reverse(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* rest = reverse(head->next);
        head->next->next = head;
 
        head->next = nullptr;
 
        return rest;
    }
    
public:
    int pairSum(ListNode* head) {
        ListNode *temp=head;
        int l = 0;
        while(temp->next!=nullptr){
            l++;
            temp=temp->next;
        }
        l++;
        int mid = l/2;
        temp=head;
        int i=0;
        ListNode* first=head;
        while(i<mid){
            first=temp;
            temp=temp->next;
            i++;
        }
        first->next=nullptr;
        temp=reverse(temp);
        int mx = -1;
        while(temp!=nullptr and head!=nullptr){
            mx=max(mx,temp->val+head->val);
            temp=temp->next;
            head=head->next;
        }
        return mx;
    }
};```



