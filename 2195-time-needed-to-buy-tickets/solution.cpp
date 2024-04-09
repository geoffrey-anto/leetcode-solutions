class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;

        for(int i=0; i<tickets.size(); i++) {
            ans += min(tickets[k], tickets[i]);
        }

        int mx = 0;

        for(int i=k+1; i<tickets.size(); i++) {
            if(tickets[i] >= tickets[k]) {
                mx++;
            }
        }

        return ans - mx;
    }
};
