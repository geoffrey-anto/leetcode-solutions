# Expression Add Operators

## Leetcode Link: [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/)
### Language: C++

```cpp
class Solution {
public:
    void solve(string nums, long long target, long long currVal, long long prev, vector<string> &ans, string cur, long long n, long long i) {
        if(n == i) {
            if (target == currVal) {
                ans.push_back(cur);
            }
            return;
        }
        for(int j=i; j<n; j++) {
            if(j > i and nums[i] == '0') {
                return;
            }

            string currSubstr = nums.substr(i, j-i+1);
            long long numValue = stol(currSubstr);

            if(cur == "") {
                solve(nums, target, numValue, numValue, ans, currSubstr, n, j+1);
                continue;
            }

            solve(nums, target, currVal + numValue, numValue, ans, cur + "+" + currSubstr, n, j+1);
            solve(nums, target, currVal - numValue, -numValue, ans, cur + '-' + currSubstr, n, j+1);

            solve(nums, target, (currVal - prev) + (numValue * prev), prev * numValue, ans, cur + '*' + currSubstr, n, j+1);
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string curr = "";
        solve(num, target, 0, 0, ans, curr, num.size(), 0);
        return ans;
    }
};```



