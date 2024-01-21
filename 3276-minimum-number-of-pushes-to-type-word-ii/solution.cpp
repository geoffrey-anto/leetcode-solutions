struct comp {
    template <typename T>
 
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first < r.first;
    }
};

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);

        for(auto &i: word){
            mp[i-'a']++;
        }

        set<pair<char, int>, comp> st;

        for(auto i=0; i<26; i++) {
            if(mp[i]) {
                st.insert({'a'+i, mp[i]});
            }
        } 

        int currCount = 1;
        int ans = 0;

        for(auto &i: st) {
            char c = i.first;
            int freq = i.second;

            if(currCount <= 8) {
                ans += (1 * freq);
            } else if(currCount <= 16) {
                ans += (1 * (2*freq));
            } else if(currCount <= 24) {
                ans += (1 * (3*freq));
            } else {
                ans += (1 * (4*freq));
            }
            currCount++;
        }

        return ans;
    }
};
