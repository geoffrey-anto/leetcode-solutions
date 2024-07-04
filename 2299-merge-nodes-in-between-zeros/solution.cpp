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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = nullptr;
        ListNode* ans = nullptr;
        int currSum = 0;

        while(head) {
            if(head->val == 0) {
                if(currSum == 0) {
                    head = head->next;
                    continue;
                }

                if(!temp) {
                    temp = new ListNode(currSum);
                    ans = temp;
                } else {
                    temp->next = new ListNode(currSum);
                    temp = temp->next;
                }

                currSum = 0;

                head = head->next;

                continue;
            }

            currSum += head->val;

            head = head->next;
        }

        return ans;
    }
};
