class Solution {
public:
    vector<int> f(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        
        vector<bool> sp(n - 1, false);
        
        for (int i = 0; i < n - 1; i++) {
            if((nums[i] % 2) != (nums[i + 1] % 2)) {
                sp[i] = true;
            }
        }

        // accumulate subrrarys with true for range opr
        vector<int> pre(n);
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + sp[i - 1];
        }

        return pre;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();

        vector<bool> res(q.size(), true);

        if (n == 1) {
            return res;
        }

        auto pre =  f(nums, q);

        int x = 0;

        for (auto& query : q) {
            // therefore the num of trues should be eq to the sub array size
            res[x] = (pre[query[1]] - pre[query[0]] == (query[1] - query[0]));
            x++;
        }

        return res;
    }
};
