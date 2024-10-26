class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;

        char prev = word[0];
        int curr = 1;
        for(int i=1; i<word.size(); i++) {
            if(prev == word[i]) {
                curr++;
                prev = word[i];
            } else {
                ans += (curr - 1);
                curr = 1;
                prev = word[i];
            }
        }

        ans += (curr - 1);

        return ans;
    }
};
