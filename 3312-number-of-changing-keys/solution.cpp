class Solution {
public:
    int getCharCode(char a) {
        if(a >= 65 and a <= 90) {
            return a - 'A';
        } else {
            return a - 'a';
        }
    }
    int countKeyChanges(string s) {
        char prev = s[0];
        
        int cnt = 0;
        
        for(int i=1; i<s.size(); i++) {
            if(getCharCode(s[i]) != getCharCode(prev)) {
                cnt++;
            }
            prev = s[i];
        }
        
        return cnt;
    }
};
