class Solution {
public:
    vector<int> diStringMatch(string s) {
        int m = 0;
        int mx = s.length();

        vector<int> ans;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'I') {
                ans.push_back(m++);
            } else {
                ans.push_back(mx--);
            }
        }

        ans.push_back(m);

        return ans;
    }
};
