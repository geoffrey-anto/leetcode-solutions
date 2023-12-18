// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int mx = INT_MIN;
//         vector<int  > ans;
//         for(int i=0; i<=nums.size()-k; i++) {
//             for(int j=i; j<i+k; j++) {
//                 mx = max(mx, nums[j]);
//             }
//             ans.push_back(mx);
//             mx = INT_MIN;
//         }
//         // lol not working TLE
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> q;
        for(int i=0; i<k; i++) {
            q.push({nums[i], i});
        }
        for(int i=k-1; i<nums.size(); i++) {
            q.push({nums[i], i});
            while(true) {
                if((i - q.top().second) >= k) {
                    q.pop();
                } else {
                    break;
                }
            }
            ans.push_back(q.top().first);
        }
        
        return ans;
    }
};