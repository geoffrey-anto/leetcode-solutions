// class Solution {
// public:
//     int beautifulSubsets(vector<int>& nums, int k) {
//         // abs(a - b) = k
//         // a = k + b;
//         // k = 100, b = 10, a = 110
//         // k = 10, b = 100, a = 110
//         // a = 10, b = 100, k = 90, a = (90 + 100)
//         // -a = k - b
//         //  a = k + b
//         // +- a = k + b;

//         // we can rule out the case that we would need a negative A, so mayb we can check for the later case
//         // a = k - b

//         int ans = 0;

//         int n = nums.size();

//         int p = 1 << n;

//         set<int> masks;

//         unordered_map<int, int> mp;
//         for(int i=0; i<p; i++) {
//             mp.clear();
//             int present = 0;
//             int curr = 0;

//             for(int j=0; j<n; j++) {
//                 if(((i & (1 << j)) != 0) and !mp[nums[j] - k] && !mp[nums[j] + k]) {
//                     present++;
//                     curr = curr | (1 << j);
//                     mp[nums[j]]++;
//                 }
//             }

//             if(present and masks.find(curr) == masks.end()) {
//                 ans++;
//                 masks.insert(curr);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    void f(vector<int> &nums, int i, int k, unordered_map<int, int> &mp, int &ans, int &take) {
        if(i == nums.size() and take) {
            ans++;
            return;
        }

        if(!mp[nums[i] - k] and !mp[nums[i] + k]) {
            mp[nums[i]]++;
            take++;
            f(nums, i + 1, k, mp, ans, take);
            mp[nums[i]]--;
        }

        f(nums, i + 1, k, mp, ans, take);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;

        unordered_map<int, int> mp;

        int take = 0;

        f(nums, 0, k, mp, ans, take);
        ans--;

        return ans;
    }
};
