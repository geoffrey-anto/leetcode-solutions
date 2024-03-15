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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head, *p = head;

        if(!head->next) {
            return nullptr;
        }

        while(fast && fast->next) {
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        p->next = p->next->next;

        return head;
    }
};
