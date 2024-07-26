// class Solution {
// public:
//     int minChanges(vector<int>& nums, int k) {
//         unordered_map<int, int> fq;

//         int n = nums.size();

//         for(int i=0; i<n/2; i++) {
//             fq[abs(nums[i] - nums[n - i - 1])]++;
//         }

//         pair<int, int> mx;

//         mx = {0, 0};

//         for(auto &[k, v]: fq) {
//             if(v > mx.second) {
//                 mx = {k, v};
//             } else if(v == mx.second) {
//                 if(k < mx.first) {
//                     mx = {k, v};
//                 }
//             } else {
//                 mx = {k, v};
//             }
//         }

//         int diff = mx.first;

//         int ans = 0;

//         for(int i=0; i<n/2; i++) {
//             if(abs(nums[i] - nums[n - i - 1]) == diff) {
//                 continue;
//             } else {
//                 int curr = abs(nums[i] - nums[n - i - 1]);

//                 if(curr < diff) {
//                     if((diff - curr > (k - nums[i])) or (diff - curr > (k - nums[i]))) {
//                         ans += 2;
//                     }
//                 } else {
//                     ans ++;
//                 }
//             }
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int minChanges(vector<int> &nums, int k)
    {
        vector<int> freq(k+1);
        vector<int> v;
        int n = nums.size();
        for (int i = 0; i < n / 2; i++){
            int dif = abs(nums[i] - nums[n - i - 1]);
            freq[dif]++;

            int a = nums[i], b = nums[n - i - 1];
            int threshold = max(max(a, b), k - min(a, b));
            v.push_back(threshold);
        }

        sort(v.begin(), v.end());

        int ans = n / 2;
        n /= 2;
        for (int i = 0; i < freq.size(); i++)
        {
            int rest = n - freq[i];
            int greater = lower_bound(v.begin(), v.end(), i) - v.begin();
            ans = min(ans, rest + greater);
        }
        return ans;
    }
};
