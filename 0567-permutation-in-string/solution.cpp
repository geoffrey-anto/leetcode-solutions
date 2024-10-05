class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for(auto i: s1) {
            mp1[i]++;
        }

        if(s1.size() > s2.size()) {
            return false;
        }

        int n = s1.size();

        for(int i=0; i<n; i++) {
            mp2[s2[i]]++;
        }

        if(mp1 == mp2) {
            return true;
        }

        for(int i=n; i<s2.size(); i++) {
            char curr = s2[i];

            mp2[s2[i - n]]--;
            
            if(mp2.find(s2[i - n]) != mp2.end() and mp2[s2[i - n]] == 0) {
                mp2.erase(s2[i - n]);
            }

            mp2[curr]++;

            if(mp1 == mp2) {
                return true;
            }
        }

        return false;
    }
};
