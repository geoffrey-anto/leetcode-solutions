class Solution {
public:
    int maximumLength(string s) {
        string temp = "";
        int n = s.size();
        unordered_map<string, int> mp;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(temp.size() >= 1 and s[j] != temp.back()) {
                    break;
                }

                temp += s[j];

                mp[temp]++;
            } 
            temp = "";
        }

        int mx = -1;

        for(auto &[k, v]: mp) {
            if(v >= 3) {
                mx = max(mx, (int)k.size());
            }
        }

        return mx;
    }
};
