// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int s1 = 0;
//         int s2 = 0;
//         int turn = 0;
//         for(auto i: nums) {
//             if(turn == 0){
//                 s1+=i;
//                 turn = 1;
//             } else {
//                 s2 += i;
//                 turn = 0;
//             }
//         }

//         return abs(s1 - s2);
//     }
// };

class Solution {
public:
    int p(int n) {
        return 1 << n;
    }
    vector<vector<int>> findSubsetSumForIdxs(vector<int> &nums, pair<int, int> &pr) {
        int s = pr.first, e = pr.second;
        int len = e - s + 1;
        vector<vector<int>> ans(len+1);

        for(int i=0; i<p(len); i++) {
            int sum = 0;
            int numCnt = 0;
            for(int j=0; j<len; j++) {
                if(i&p(j)) {
                    sum += nums[s + j];
                    numCnt++;
                }

            }
            ans[numCnt].push_back(sum);
        }

        return ans;
        
    }
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;
        pair<int, int> lh = {0, n-1};
        pair<int, int> rh = {n, N-1};

        vector<vector<int>> leftSum = findSubsetSumForIdxs(nums, lh);
        vector<vector<int>> rightSum = findSubsetSumForIdxs(nums, rh);

        // for(auto i: leftSum) {
        //     for(auto j: i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for(auto i: rightSum) {
        //     for(auto j: i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }

        int tSum = 0;
        for(auto i: nums) {
            tSum += i;
        }

        int t = tSum / 2;

        int ans = 1e9;

        for(int i = 0; i <= n; i++) {
            vector<int> r = rightSum[n-i];

            sort(r.begin(), r.end());
            cout << i << endl;
            for(auto l: leftSum[i]) {
                auto val = lower_bound(r.begin(), r.end(), t-l);
                if(val != r.end()) {
                    ans = min(ans, abs(tSum - 2 * (l + *val)));
                }
            }
        }



        return ans;
    }
};