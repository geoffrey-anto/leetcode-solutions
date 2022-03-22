class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        // for(auto &i:nums){
        //     pq.push(i);
        // }
        // for(int i=0;i<k;i++){
        //     if(i==k-1){
        //         return pq.top();
        //     }
        //     pq.pop();
        // }
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};