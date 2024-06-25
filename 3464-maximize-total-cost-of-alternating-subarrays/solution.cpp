// // class Solution {
// // public: 
// //     vector<long long> dp;
// //     long long f(int i, vector<int>& nums) {
// //         if(i == nums.size()) {
// //             return 0;
// //         }

// //         if(dp[i] != -1) return dp[i];

// //         long long ans = LLONG_MIN;
// //         long long curr = 0;

// //         for(int idx=i; idx<nums.size(); idx++) {
// //             curr += nums[idx] * pow(-1, idx - i); 
// //             ans = max(ans, curr + f(idx+1, nums));
// //         }

// //         return dp[i] = ans;
// //     }

// //     long long maximumTotalCost(vector<int>& nums) {
// //         dp = vector<long long>(nums.size()+1, -1);

// //         // for(int i=nums.size()-1; i>=0; i--) {
// //             long long ans = LLONG_MIN;
// //             long long curr = 0;

// //             for(int idx=i; idx<nums.size(); idx++) {
// //                 curr += nums[idx] * pow(-1, idx - i); 
// //                 ans = max(ans, curr + dp[idx+1]);
// //             }

// //             dp[i] = ans;
// //         // }

// //         return dp[0];
// //     }
// // };

// class Solution {
// public:
//     vector<vector<long long>> dp;
//     long long f(int i, bool p, vector<int>& nums) {
//         if(i == nums.size()) {
//             return 0;
//         }

//         if(dp[i][p] != -1) {
//             return dp[i][p];
//         }

//         long long nt = nums[i] + f(i+1, false, nums);

//         long long t = 0;

//         if(p) {
//             t = nums[i] + f(i+1, false, nums);
//         } else {
//             t = - nums[i] + f(i+1, true, nums);
//         }

//         return dp[i][p] = max(nt, t);
//     }

//     long long maximumTotalCost(vector<int>& nums) {
//         vector<long long> prev(2, 0), curr(2, 0);

//         for(int i=nums.size()-1; i>=0; i--) {
//             for(int p=0; p<=1; p++) {
//                 long long nt = nums[i] + prev[false];

//                 long long t = 0;

//                 if(p) {
//                     t = nums[i] + prev[false];
//                 } else {
//                     t = - nums[i] + prev[true];
//                 }

//                 curr[p] = max(nt, t);
//             }
//             prev = curr;
//         }

//         return curr[true];
//         // return f(0, true, nums);
//     }
// };

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long a = 0ll, b = 0ll, c = 0ll, d = 0ll;

        for(int i=nums.size()-1; i>=0; i--) {
            long long nt = nums[i] + c;

            long long t = 0;

            if(true) {
                t = nums[i] + c;
            } else {
                t = - nums[i] + d;
            }

            b = max(nt, t);

            nt = nums[i] + c;

            t = 0;

            if(false) {
                t = nums[i] + c;
            } else {
                t = - nums[i] + d;
            }

            a = max(nt, t);

            c = a; d = b;
        }

        return d;
    }
};
