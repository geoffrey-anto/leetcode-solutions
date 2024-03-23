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
    ListNode* middle(ListNode* head) {
        auto slow = head;
        auto fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* rev(ListNode* head) {
        if(!head) return nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;


        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        auto mid = middle(head);

        auto s = rev(mid->next);

        mid->next = nullptr;
        mid = head;

        ListNode*l,*r;

        while(s)
        {
            l=mid->next;

            r=s->next;

            mid->next=s;

            s->next=l;

            mid=l;
            s=r;
        }

    }
};
