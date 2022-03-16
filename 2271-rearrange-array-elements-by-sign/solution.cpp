class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i=0;
        int j=1;
        int n = nums.size();
        vector<int> arr(n,-1);
        for(auto num:nums){
            if(num>0){
                arr[i]=num;
                i+=2;
            } else{
                arr[j]=num;
                j+=2;
            }
        }
        return arr;
    }
};
