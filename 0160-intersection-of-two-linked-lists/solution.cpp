/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0;
        auto temp = headA;

        while(temp) {
            temp = temp->next;
            a++;
        }

        int b = 0;

        temp = headB;

        while(temp) {
            temp = temp->next;
            b++;
        }

        ListNode* aa = headA;
        ListNode* bb = headB;

        if(b > a) {
            swap(a, b);
            aa = headB;
            bb = headA;
        }

        int d = a - b;

        while(d--) {
            aa = aa->next;
        }

        while(aa && bb) {
            if(aa == bb) {
                return aa;
            }

            aa = aa->next;
            bb = bb->next;
        }

        return nullptr;
    }
};
