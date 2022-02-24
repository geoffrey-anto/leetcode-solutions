class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int l = nums.size();
        vector<int> arr(l);
        for(int i=0;i<l;i++){
            arr[i] = nums[nums[i]];
        }
        return arr;
    }
};