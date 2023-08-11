class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int can = 0;

        for(auto &i: nums) {
            if(cnt==0){
                can = i;
            }

            if(i == can) {
                cnt++;
            } else {
                cnt--;
            }
        }

        return can;
    }
};
