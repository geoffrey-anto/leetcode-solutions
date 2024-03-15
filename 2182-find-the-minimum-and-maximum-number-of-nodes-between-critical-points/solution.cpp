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
    vector<int> f(ListNode* head) {
        int mnDist = INT_MAX;
        int prevIdx = -1;
        int firstNodePos = -1;

        int lastNodePos = -1;
        ListNode* temp = head->next;
        ListNode* prev = head;

        int i = 1;

        while(temp && temp->next) {
            int p = prev->val;
            int c = temp->val;
            int n = temp->next->val;

            if((c > p && c > n) || (c < p && c < n)) {
                if(prevIdx != -1)
                    mnDist = min(mnDist, i - prevIdx);

                prevIdx = i;

                if(firstNodePos == -1) {
                    firstNodePos = i;
                }

                lastNodePos = i;
            }

            i++;
            prev = temp;
            temp = temp->next;
        }


        if(mnDist == INT_MAX) {
            if(firstNodePos == lastNodePos) {
                return {-1, -1};
            }
            return {-1, lastNodePos - firstNodePos};
        }

        return {mnDist, lastNodePos - firstNodePos};
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        return f(head);
    }
};
