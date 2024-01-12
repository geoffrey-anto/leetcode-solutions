class Solution {
public:
    string largestMerge(string s1, string s2) {
        if (s1.size() == 0  || s2.size() == 0)
            return s1 + s2;
        if (s1 > s2)
            return s1[0] + largestMerge(s1.substr(1), s2);
        return s2[0] + largestMerge(s1, s2.substr(1));
    }
    string largestMerge_(string word1, string word2) {
        string ans = "";
        int i = 0;
        int j = 0;

        int n = word1.size();
        int m = word2.size();

        while(i < n && j < m) {
            if(word1[i] == word2[j]) {
                if(((n - i) >= (m - j))) {
                    ans += word1[i];
                    i++;
                } else {
                    ans += word2[j];
                    j++;
                }
            } else if(word1[i] > word2[j]) {
                ans += word1[i];
                i++;
            } else {
                ans += word2[j];
                j++;
            }
        }

        cout << i << " " << j << endl;

        while(i < n) {
            ans += word1[i];
            i++;
        }

        while(j < m) {
            ans += word2[j];
            j++;
        }

        return ans;
    }
};
