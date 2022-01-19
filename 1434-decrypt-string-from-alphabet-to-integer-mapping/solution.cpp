class Solution {
public:
    string freqAlphabets(string s) {
        int n=s.size();
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(s[i]=='#' and i>1){
                ans=ans+char(96+stoi(s.substr(i-2,i)));
                i=i-2;
            } else {
                ans=ans+char(96+int(s[i])-48);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
