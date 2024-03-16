class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = accumulate(begin(nums), end(nums), 0ll);
        
        int n = nums.size();
        
        vector<int> idxs;
        
        vector<long long> ans;
        
        for(int i=0; i<nums.size(); i++) {
            idxs.push_back(i);
        }
        
        sort(begin(idxs), end(idxs), [&](int &a, int &b) {
            if(nums[a] == nums[b]) {
                return a < b;
            }
            return nums[a] < nums[b]; 
        });
        
        int pos = 0;
        
        
        for(int i=0; i<queries.size(); i++) {
            int idx = queries[i][0];
            int k = queries[i][1];
            
            if(nums[idx] != -1){
                sum -= nums[idx];
                nums[idx] = -1;  
            }
            
            
            while(k && pos < nums.size()) {
                if(nums[idxs[pos]] != -1) {
                    sum -= nums[idxs[pos]];
                    k--;
                    nums[idxs[pos]] = -1;
                    pos++;
                } else {
                    pos++;
                }
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};
