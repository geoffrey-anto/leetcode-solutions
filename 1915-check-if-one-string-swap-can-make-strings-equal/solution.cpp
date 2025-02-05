class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }

        int count = 0;
        int a = -1;
        int b = -1;

        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                count ++;
                if(a == -1) {
                    a = i;
                } else if(b == -1) {
                    b = i;
                }
            }
        }

        return (count == 0) or (count == 2 && ((s1[a] == s2[b]) and (s1[b] == s2[a])));
    }
};
