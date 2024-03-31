class Solution {
public:
    // int fun(int f, int e, int ex) {
//         if(f <= 0 and e < ex) {
//             return 0;
//         }
                
//         int a = 0;
//         if(f > 0)
//             a = 1 + max(a, fun(f-1, e+1, ex));
        
//         int b = 0;
//         if(e >= ex) {
//             b = fun(f+1, e-ex, ex+1);
//         }
        
//         return a + b;
    // }
    int maxBottlesDrunk(int numBottles, int numExchange) {
        // return fun(numBottles, 0, numExchange);
        
        int ans = 0;
        int e = 0;
        
        while(true) {
            if(numBottles <= 0 && e < numExchange) {
                break;
            }
            if(numBottles > 0) {
                ans += numBottles;
                e += numBottles;
                numBottles = 0;
            }
            
            while(e >= numExchange) {
                numBottles += 1;
                e -= numExchange;
                numExchange++;
            }
        }
        
        return ans;
    }
};
