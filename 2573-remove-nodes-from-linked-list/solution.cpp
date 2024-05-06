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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        int mx = 0;

        ListNode* temp = head;

        while(temp && temp->next) {
            if(temp->val > temp->next->val) {
                temp->next = temp->next->next;
                continue;
            }

            temp = temp->next;
        }

        head = reverse(head);

        return head;
    }
};
