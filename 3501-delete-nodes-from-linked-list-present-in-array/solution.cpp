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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end(nums));

        ListNode* temp = new ListNode(-1);
        ListNode* ref = temp;

        while(head) {
            if(st.find(head->val) != st.end()) {
                
            } else {
                ref->next = head;
                ref = ref->next;
            }

            head = head->next;
        }

        ref->next = nullptr;

        return temp->next;
    }
};
