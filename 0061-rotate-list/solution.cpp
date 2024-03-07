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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return head;
        } 

        ListNode* temp = head;
        int n = 1;

        while(temp->next) {
            temp = temp->next;
            n++;
        }

        k = k % n;

        ListNode* tail = temp;

        tail->next = head;

        // cout << tail->next->val << endl;

        int moves = n - k;
        temp = head;

        while(moves > 1) {
            temp = temp->next;
            moves--;
        }

        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return newHead;
    }
};
