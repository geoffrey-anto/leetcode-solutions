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
    ListNode* reverse(ListNode* head)
    {
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        int mul = 2;
        int carry = 0;
        ListNode* temp = head;

        while((mul || carry) && (temp)) {
            int c = (temp->val * 2) + carry;

            temp->val = c%10;
            carry = c > 9;
                       
            
            temp = temp->next;
        }

        if(carry != 0) {
            ListNode* t = head;
            while(t->next) {
                t = t->next;
            }
            t->next = new ListNode(1);
        }

        return reverse(head);
    }
};
