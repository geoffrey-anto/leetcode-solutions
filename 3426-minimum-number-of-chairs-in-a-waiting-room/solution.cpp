class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int cnt = 0;
        for(auto i: s) {
            if(i == 'E') {
                cnt++;
            } else {
                cnt--;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
