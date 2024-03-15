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
    ListNode* oddEvenList(ListNode* head) {
        if (!head or !head->next or !head->next->next) {
            return head;
        }

        ListNode *o= head, *e = head->next, *eHead = head->next;

        while(e and e->next){
            o->next = o->next->next;
            e->next = e->next->next;
            o = o->next;
            e = e->next;
        }
        
        o->next = eHead;

        return head;
    }
};
