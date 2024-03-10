class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long ans = 0ll;
        
        for(long long i=0; i<k; i++) {
            ans += max((long long)happiness[i] - i, 0ll);
        }
        
        return ans;
    }
};
