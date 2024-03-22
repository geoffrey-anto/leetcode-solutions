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
    bool isPalindrome(ListNode* head) {
        ListNode* rev = nullptr;

        ListNode* temp = head;

        while(temp){
            ListNode* t = new ListNode(temp->val);
            t->next = rev;
            rev = t;
            temp = temp->next;
        }

        temp = head;

        while(rev && temp) {
            if(rev->val != temp->val) {
                return false;
            }
            rev = rev->next;
            temp = temp->next;
        }

        return true;

    }
};
