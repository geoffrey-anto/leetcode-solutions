class Solution {
public:
    // Exactly(k) = atmost(k) - atmost(k-1);
    int countSubarraysWithKDistinct(vector<int>& nums, int k) {
        std::map<int, int> freq;
        int i = 0;
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            freq[nums[j]]++;
            while (freq.size() > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) freq.erase(nums[i]);
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int atMostK = countSubarraysWithKDistinct(nums, k);
        int atMostKMinusOne = countSubarraysWithKDistinct(nums, k - 1);
        return atMostK - atMostKMinusOne;
    }
};

