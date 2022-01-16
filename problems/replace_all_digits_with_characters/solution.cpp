class Solution {
public:
    string replaceDigits(string s) {
        int n=s.size();
        string ans = "";
        for(int i=0;i<n;i++){
            if((i+1)%2==0){
                ans=ans+char(int(s[i])-48+int(s[i-1]));
            } else {
                ans=ans+s[i];
            }
        }
        return ans;
    }
};