class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> map;
        for(auto i:nums){
            map[i]++;
        }
        for(auto [i,c]:map){
            ans=ans+(c*(c-1))/2;
        }
        return ans;
    }
};