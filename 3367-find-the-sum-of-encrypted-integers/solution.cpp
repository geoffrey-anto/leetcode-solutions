class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(auto &i: nums) {
            int mx = 0;
            int cnt = 0;
            while(i) {
                mx = max(mx, i % 10);
                i = i / 10;
                cnt++;
            }
            int val = 0;
            while(cnt) {
                val = val*10 + mx;
                cnt--;
            }
            
            ans += val;
        }
        
        return ans;
    }
};
