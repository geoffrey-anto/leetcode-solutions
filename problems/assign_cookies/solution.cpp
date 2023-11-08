class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;

        int ptrg = 0;
        int ptrs = 0;

        int n = g.size();
        int m = s.size();
        while(ptrg < n and ptrs < m) {
            if(g[ptrg] > s[ptrs]) {
                ptrs++;
            } else {
                ans++;
                ptrs++;
                ptrg++;
            }
        }
        return ans;
    }
};