class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        int ans = 1;

        int i = 0;
        int j = k;

        // Basically check if there is a prefix where word[j:] is present
        // if there return ans
        while(j<n) {
            if(word.starts_with(word.substr(j))) {
                return ans;
            }
            j+=k;
            ans++;
        }

        return ans;
    }
};
