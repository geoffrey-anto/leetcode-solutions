class Solution {
public:
    vector<char> v = {'a', 'e', 'i', 'o', 'u'};

    int countVowelStrings(int n) {
        vector<int> dp(5, 1);

        while(n>1){
            for(int i=1; i<5; i++) {
                dp[i] += dp[i-1];
            }
            n--;
        }

        int sum = 0;

        sum = accumulate(begin(dp), end(dp), sum);

        return sum;
    }
};
