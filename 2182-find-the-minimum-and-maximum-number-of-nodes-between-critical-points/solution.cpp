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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pts;

        int prev = head->val;

        int pos = 1;
        head = head->next;

        while(head and head->next) {
            int val = head->val;

            int nx = head->next->val;

            if((val > nx and val > prev) or (val < nx and val < prev)) {
                pts.push_back(pos);
            }
            prev = head->val;

            head = head->next;
            pos++;
        }

        // for(auto i: pts) {
        //     cout << i << endl;
        // }

        vector<int> ans(2, INT_MAX);

        if(pts.size() < 2) {
            return  {-1, -1};
        }

        ans[1] = pts[pts.size() - 1] - pts[0]; 

        sort(begin(pts), end(pts));

        for(int i=0; i<pts.size()-1; i++) {
            ans[0] = min(ans[0], pts[i+1] - pts[i]);
        }

        return ans;
    }
};
