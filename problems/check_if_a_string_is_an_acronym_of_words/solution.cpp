class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(words.size() != s.length()) return false;
        int cnt = 0;
        for(auto &i: words) {
            if(s[cnt] != i[0]){
                return false;
            }
            cnt++;
        }
        return true;
    }
};