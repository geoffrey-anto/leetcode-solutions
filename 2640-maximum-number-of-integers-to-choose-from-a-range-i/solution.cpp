class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, bool> mp;
        for(auto i: banned) {
            mp[i]=true;
        }
        
        int cnt = 0;
        long long s = 0;
        
        for(int i=1; i<=n; i++) {
            if(mp[i]) {
                continue;
            } else {
                if(s + i > maxSum) {
                    break;
                }
                cnt++;
                s += i;
            }
        }
        
        return cnt;
    }
};
