class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size();
        n=n/2;
        for(auto &i:nums){
            map[i]++;
            if(map[i] >= n){
                return i;
            }
        }
        return -1;
    }
};