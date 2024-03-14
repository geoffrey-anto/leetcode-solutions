class Solution {
public:
    
    long long f(vector<int> &h, int &n, int &mxI) {
        long long ans = h[mxI];
        
        long long a = 0;
        for(int i=mxI-1; i>=0; i--) {
            if(h[i] <= ans) {
                ans = h[i];
            }
            a += (ans);
        }
        
        long long ans2 = h[mxI];
        long long b = 0;
        
        for(int i=mxI+1; i<n; i++) {
            if(h[i] <= ans2) {
                ans2 = h[i];
            }
            
             b += ans2;
        }
        
        return a + b + h[mxI];
    }
    
    long long maximumSumOfHeights(vector<int>& h) {
        int n = h.size();

        long long ans = 0;
        
        for(int i=0; i<n; i++) {
            ans = max(ans, f(h, n, i));
        }
        
        return ans;
    }
};
