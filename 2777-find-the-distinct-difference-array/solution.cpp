class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> pre;
        unordered_map<int, int> suf;
        
        int n = nums.size();
        
        
        vector<int> v;
        
        for(int i=0; i<n; i++) {
            
                suf[nums[i]]++;
           
        }
        
        for(int i=0; i<n; i++) {
            pre[nums[i]]++;
            suf[nums[i]]--;
            
            
            if(suf[nums[i]] == 0 or suf[nums[i]] <= 0) {
                suf.erase(nums[i]);
            }
            
            
            v.push_back(pre.size()-suf.size());
            
        }
        return v;
    }
};
