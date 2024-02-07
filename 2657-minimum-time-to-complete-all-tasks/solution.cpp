class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        unordered_map<int, bool> mp;

        for(auto &t: tasks) {
            for(int i=t[0]; i<=t[1]; i++) {
                if(mp[i]) {
                    t[2]--;
                }
            }

            for(int i=t[1]; t[2]>0; i--) {
                if(mp[i]) continue;
                t[2]--;
                mp[i] = true;
            }
        }

        int ans = 0;

        for(auto &[k, v]: mp) {
            if(v) ans++;
        }

        return ans;
    }
};
