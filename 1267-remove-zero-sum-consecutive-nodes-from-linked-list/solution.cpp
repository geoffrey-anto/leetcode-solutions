#define Node ListNode
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* i = new Node(-1001);
        auto cpy = i;
        i->next = head;
        
        while(i) {
            Node* j = i->next;  
            int runningSum = 0;

            while(j != nullptr) {
                runningSum += j->val;

                if(runningSum == 0) {
                    i->next = j->next;
                }

                j = j->next;
            }
            i = i->next;
        }

        return cpy->next;
    }
};
