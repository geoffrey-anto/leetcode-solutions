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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l2End = list2;
        while(l2End->next) {
            l2End = l2End->next;
        }

        ListNode* APt = list1;
        int i = 0;

        while(APt && i+1 != a) {
            i++;
            APt = APt->next;
        }




        ListNode* bPt = list1;
        int j = 0;

        while(bPt && j != b+1) {
            bPt = bPt->next;
            j++;
        }

        APt->next = list2;

        l2End->next = bPt;

        return list1;
    }
};
