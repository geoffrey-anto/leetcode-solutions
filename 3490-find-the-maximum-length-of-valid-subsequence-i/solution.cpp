class Solution {
public:
    bool isOdd(int a) {
        return a % 2 != 0;
    }
    
    bool isEven(int a) {
        return a % 2 == 0;
    }
//     // even -> 1
//     int f(int b, int par, int a, vector<int>& nums, vector<vector<vector<int>>> &dp) {
//         if(b == nums.size()) {
//             return 0;
//         }
        
//         if(dp[b][par+1][a+1] != -1) {
//             return dp[b][par+1][a+1];
//         }
        
//         int nt = f(b+1, par, a, nums, dp);
        
//         int ans = 0;
        
//         if(par == 1) {
//             if(a == -1) {
//                 ans = max(ans, 1 + f(b+1, par, nums[b] % 2 == 0, nums, dp));
//             }
            
//             if(a == 0 && isEven(nums[b])) {
//                 ans = max(ans, 1 + f(b+1, par, nums[b] % 2 == 0, nums, dp));
//             }
                          
//             if(a == 1 && isOdd(nums[b])) {
//                 ans = max(ans, 1 + f(b+1, par, nums[b] % 2 == 0, nums, dp));
//             }
//         } else {
//             if(a == -1) {
//                 ans = max(ans, 1 + f(b+1, par, nums[b] % 2 == 0, nums, dp));
//             }
            
//             if(a == 0 && isOdd(nums[b])) {
//                 ans = max(ans, 1 + f(b+1, par, nums[b] % 2 == 0, nums, dp));
//             }
                          
//             if(a == 1 && isEven(nums[b])) {
//                 ans = max(ans, 1 + f(b+1, par, nums[b] % 2 == 0, nums, dp));
//             }
//         }
        
//         return dp[b][par+1][a+1] = max(ans, nt);
//     }
    
    int maximumLength(vector<int>& nums) {
        // observations
        /*
            basically odd or even parity
            let the first 2 elements be a and b
            
            case 1) parity of odd
                a = odd
                b = even
                
                a = even
                b = odd
                
            case 2) parity of even
                a = odd
                b = odd
                
                a = even
                b = even
        */
        
        vector<unordered_map<int, int>> curr(2, unordered_map<int, int>()), prev(2, unordered_map<int, int>());
        
        for(int b=nums.size()-1; b>=0; b--) {
            for(int par=1; par>=0; par--) {
                for(int a=1; a>=-1; a--) {
                    int nt = prev[par][a];
        
                    int ans = 0;

                    if(par == 1) {
                        if(a == -1 or (a == 0 && isEven(nums[b])) or (a == 1 && isOdd(nums[b]))) {
                            ans = max(ans, 1 + prev[par][nums[b] % 2 == 0]);
                        }
                    } else {
                        if(a == -1 or (a == 0 && isOdd(nums[b])) or (a == 1 && isEven(nums[b]))) {
                            ans = max(ans, 1 + prev[par][nums[b] % 2 == 0]);
                        }
                    }

                    curr[par][a] = max(ans, nt);
                }
            }
            prev = curr;
        }
        
        return max(curr[1][-1], curr[0][-1]);
    }
};
