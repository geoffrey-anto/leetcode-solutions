#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

class Solution {
public:
    int dp[2 * (int)(5 * 1e4) + 1];
    int f(int currVal, ordered_set &s) {
        if(currVal <= 0) {
            return 0;
        }

        if(dp[currVal] != -1) {
            return dp[currVal];
        }

        int ub = s.order_of_key(currVal+1);

        int ans = 0;

        for(int i=0; i<ub; i++) {
            int takeVal = *s.find_by_order(i);

            // cout << takeVal << " , " <<  currVal - takeVal << endl;

            int nextVal = currVal - takeVal;

            if(nextVal >= takeVal) {
                nextVal = takeVal - 1;
            }

            // we have to take the fathest to the right we can take
            // therefor we have to take the min of the window size of currVal and takeVal
            // or the 

            if(s.find(currVal) != s.end()) {
                ans = max(ans, takeVal + 0);
                continue;
            }

            int t = takeVal + f(nextVal, s);

            ans = max(ans, t);
        }

        // cout << currVal << endl;

        // cout << ans << endl;

        // cout << endl;

        return dp[currVal] = ans;
    }

    int solve(vector<int>& rewardValues) {
        int n = rewardValues.size();

        int take = rewardValues[n-1];

        ordered_set s;

        for(auto i: rewardValues) {
            s.insert(i);
        }

        int lower = f(take-1, s);

        return take + lower;
    }

    int maxTotalReward(vector<int>& rewardValues) {
        // 2 * 5*10^4 = 10^5

        // since the max values we can get as an answer can be approx 1e5

        // we can maybe bs on the answers to get the optimal one

        // we need a O(n) soln to check if a given value can be obtained from the array

        // 1 2 3 4 6

        // 0 ..... 16

        // m = 8 > ? can we get a value 8 > 6, 4, 1 > TRUE

        // l = 9 > m = 12 ? can we get value 12 > 

        // maybe we can bs on the sorted array only

        // like 1 4, 6, 8, 12, 17

        // if we take the first val 17 since its the maximum value we can take 

        // then we do a bs on the left half to find the ub to search currVal - takenVal

        // we should also try out other combinatiins like 8 and 6 too that might lead to a better option

        // maybe we can cache that result with space max(arr);

        memset(dp, -1, sizeof(dp));

        sort(begin(rewardValues), end(rewardValues));

        return solve(rewardValues);
    }
};
