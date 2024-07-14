class Solution {
public:
    string getSmallestString(string s) {
        string ans = s;

        for(int i=0; i<s.size()-1; i++) {
            string temp = s;

            if((temp[i] - '0') % 2 == (temp[i+1] - '0') % 2) {
                swap(temp[i], temp[i+1]);
            }  

            ans = min(ans, temp);
        }

        return ans;
    }
};
