class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // int can = INT_MIN;
        // int v = 0;
        // int n = nums.size();
        // vector<int> ans;

        // for(int i=0; i<n; i++) {
        //     if(v == 0) {
        //         can = nums[i];
        //         v=1;
        //     } else {
        //         if(can == nums[i]) {
        //             v++;
        //         } else {
        //             v--;
        //         }
        //     }
                
        // }
        // cout << can;

        // int cnt = 0;

        // for(int i=0; i<n; i++) {
        //     if(nums[i] == can) {
        //         cnt++;
        //     }
        // }

        // if(cnt > n/3) {
        //     ans.push_back(can);
        // }

        // int can2 = INT_MIN;
        // int v2 = 0;

        // for(int i=0; i<n; i++) {
        //     if(nums[i] == can) {
        //         continue;
        //     }

        //     if(v2 == 0) {
        //         can2 = nums[i];
        //     } else {
        //         if(can2 == nums[i]) {
        //             v2++;
        //         } else {
        //             v2--;
        //         }
        //     }

            
        // }

        // cnt = 0;

        // for(int i=0; i<n; i++) {
        //     if(nums[i] == can2) {
        //         cnt++;
        //     }
        // }

        // if(cnt > n/3) {
        //     ans.push_back(can2);
        // } 

        // return ans;

        int cnt1 = 0;
        int e1 = 0;
        int cnt2 = 0;
        int e2 = 0;

        for(auto i: nums) {
            if(cnt1 == 0 && i != e2) {
                cnt1=1;
                e1 = i;
            } else if (cnt2 == 0 && i != e1) {
                cnt2 = 1;
                e2 = i;
            } else if(e1 == i) {
                cnt1++;
            } else if(e2 == i) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        int c1=0, c2=0;

        for(auto i:nums) {
            if(e1 == i) {
                c1++;
            }
            if(e2 == i) {
                c2++;
            }
        }

        if(c1 > nums.size()/3 && c2 > nums.size()/3) {
            if(e1 == e2) {
                return {e1};
            } else {
                return {e1, e2};
            }
        } else if(c1 > nums.size()/3) {
            return {e1};
        } else if (c2 > nums.size()/3) {
            return {e2};
        } else {
            return {};
        }
    }
};
