class Solution {
public:
    int dp[1005][1005];
    int f(int i, int j, vector<int>& nums, int &k) {
        if(i == nums.size()) {
            return 0;
        }

        if(dp[i][j+1] != -1) {
            return dp[i][j+1];
        }

        if(j == -1) {
            int nt = f(i+1, j, nums, k);

            int t = 0;

            for(int x=i+1; x < nums.size(); x++) {
                int md = (nums[i] + nums[x]) % k;

                t = max(t, 1 + f(x, md, nums, k));
            }

            return dp[i][j+1] = max(t, nt);
        } else {
            int t = 0;

            for(int x=i+1; x < nums.size(); x++) {
                int md = (nums[i] + nums[x]) % k;
                if(md == j) {
                    t = max(t, 1 + f(x, md, nums, k));
                    break;
                }
            }

            return dp[i][j+1] = t;
        }  
    }

    int maximumLength(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));

        return f(0, -1, nums, k) + 1;
    }
};

// class Solution {
// public:
//     int dp[1005][1005];
//     // int f(int i, int j, vector<int>& nums, int &k) {
//     //     if(i == nums.size()) {
//     //         return 0;
//     //     }

//     //     if(dp[i][j+1] != -1) {
//     //         return dp[i][j+1];
//     //     }

        
//     // }

//     int maximumLength(vector<int>& nums, int k) {
//         memset(dp, 0, sizeof(dp));

//         for(int i=nums.size()-1; i>=0; i--) {
//             for(int j=k; j>=-1; j--) {
//                 cout << dp[i][j+1] << endl;
//                 if(j == -1) {
//                     int nt = dp[i+1][0];

//                     int t = 0;

//                     for(int x=i+1; x < nums.size(); x++) {
//                         int md = (nums[i] + nums[x]) % k;

//                         t = max(t, 1 + dp[x][md]);
//                     }

//                     dp[i][j+1] = max(t, nt);
//                 } else {
//                     int t = 0;

//                     for(int x=i+1; x < nums.size(); x++) {
//                         int md = (nums[i] + nums[x]) % k;
//                         if(md == j) {
//                             t = max(t, 1 + dp[x][md]);
//                             break;
//                         }
//                     }

//                     dp[i][j+1] = t;
//                 }  
//             }
//         }

//         return dp[0][0] + 1;
//     }
// };
