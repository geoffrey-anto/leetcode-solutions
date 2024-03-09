class Solution {
public:
    // knapsack lol with pq: take first K for r1 and rest for r2;
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();

        vector<int> idxs(n, 0);
        for(int i=0; i<n; i++) {
            idxs[i] = i;
        }

        sort(begin(idxs), end(idxs), [&](const int &a, const int& b) {
            return (reward1[a] - reward2[a]) > (reward1[b] - reward2[b]);
        });

        int ans = 0;

        for(auto i: idxs) {
            if(k > 0) {
                ans += reward1[i];
                k--;
            } else {
                ans += reward2[i];
            }
        }

        return ans;
    }
};
