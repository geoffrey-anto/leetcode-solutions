class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = "";

        for(int i=0; i<s.size(); i++) {
            int nx = (i + k) % s.size();

            ans += s[nx];
        }

        return ans;
    }
};
