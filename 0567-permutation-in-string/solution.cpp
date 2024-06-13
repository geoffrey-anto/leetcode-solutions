class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26), mp2(26);

        if(s2.size() < s1.size()) {
            return false;
        }

        for(auto i: s1) {
            mp1[i - 'a']++;
        }

        for(int i=0; i<s1.size()-1; i++) {
            mp2[s2[i] - 'a']++;
        };

        for(int i=s1.size()-1; i<s2.size(); i++) {
            mp2[s2[i] - 'a']++;

            if(mp1 == mp2) {
                return true;
            } else {
                mp2[s2[i - s1.size() + 1] - 'a']--;
            }
        }

        return false;
    }
};
