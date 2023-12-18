# Palindrome Linked List

## Leetcode Link: [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)
### Language: C++

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode*temp=head;
        string s="";
        while(temp!=NULL){
            s+=temp->val;
            temp=temp->next;
        }
        string st=s;
        reverse(begin(s),end(s));
        return st==s?true:false;
    }
};```



