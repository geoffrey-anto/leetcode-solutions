// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for(auto &i: nums){
//             freq[i]++;
//         }
//         vector<int> ans;
//         for(auto &i: freq) {
//             if(i.second > nums.size()/3) {
//                 ans.push_back(i.first);
//             }
//         }
//         return ans;
//     } 
// };

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // so at max only 2 elements can be there
        // len(ans) <= 2
        // moore voting algo

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
