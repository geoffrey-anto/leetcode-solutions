class Solution {
public:
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode* h = new ListNode(INT_MIN);
        ListNode* t = h;

        for(auto l : lists)  {
            if(l != NULL) pq.push({l->val, l});
        }

        while(!pq.empty()){
            ListNode* minNode = pq.top().second;
            pq.pop();
            if(minNode->next != NULL) {
                pq.push({minNode->next->val, minNode->next});
            }

            t->next = minNode;
            t = t->next;
        }
        return h->next;
    }
};
