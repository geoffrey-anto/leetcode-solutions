class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int cnt = 0;
        int idx = 0;
        while(true) {
            if(idx >= s1.length() or idx >= s2.length() or idx >= s3.length()) {
                break;
            }
            if((s1[idx] == s2[idx]) && (s2[idx] == s3[idx])) {
                cnt++;
                idx++;
            } else {
                break;
            }
        }

        // so we have cnt similar
        // so we have to remove elements after pos of ""cnt""
        // so we subtract len of str - cnt

        int d1 = s1.length() - cnt;
        int d2 = s2.length() - cnt;
        int d3 = s3.length() - cnt;
        
        
        return cnt != 0 ? d1 + d2 + d3 : -1;
    }
};
