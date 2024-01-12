class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans = 0;

        int n = s.size();

        while(true) {
            bool flag = false;

            for (int i = 0; i < n - 1; ++i) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    swap(s[i], s[i + 1]);
                    i++;
                    flag = true;
                }
            }

            ans += flag;

            if(!flag) {
                break;
            }
        }
        return ans;
    }
};
