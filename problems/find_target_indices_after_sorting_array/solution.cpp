class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int pos=0;
        int rep=0;
        for(auto &i:nums){
            if(i<target){
                pos++;
            }
            if(i==target){
                rep++;
            }
        }
        vector<int> ans;
        for(int i=0;i<rep;i++){
            ans.push_back(pos+i);
        }
        return ans;
    }
};