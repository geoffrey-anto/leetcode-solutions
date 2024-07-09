class Solution {
public:
    int n = 0;
    
//     int f(int x, int t) {
        
//     }
    
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = minutesToTest / minutesToDie;
        
        n = buckets;
        
        int ans = 0;
        
        while(true) {
            if(pow((tests + 1), ans) >= buckets) {
                return ans;
            }
            
            ans ++;
        }
        
        return ans;
    }
};
