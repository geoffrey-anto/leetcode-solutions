class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> arr(n);
        int x = 0;
        for(int i=0;i<n;i+=2){
            arr[i] = nums[x];
            x++;
        }
        for(int i=1;i<n;i+=2){
            arr[i] = nums[x];
            x++;
        }
        return arr;
    }
};
