class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      	vector<int> idxMap(nums.size(), 0);
      
    	for(int i=0; i<nums.size(); i++) {
          idxMap[i] = i;
        }
      	
        sort(idxMap.begin(),idxMap.end(), [&](auto &a, auto &b) {
          if(nums[a] < nums[b]) {
            	return true;
          }
          return false;
        });
      	
        int left=0;
        int right=nums.size()-1;
      
        while(left<right){
            if(nums[idxMap[left]]+nums[idxMap[right]]==target){
                return {idxMap[left],idxMap[right]};
            }
            else if(nums[idxMap[left]]+nums[idxMap[right]]<target){
                left++;
            }
            else{
                right--;
            }
        }
      
        return {};
    }
};
