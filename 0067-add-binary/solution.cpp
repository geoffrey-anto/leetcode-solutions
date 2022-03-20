class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        string ans="";
        while(i>=0 or j>=0 or carry){
            if(i>=0){
                carry+=a[i]-'0';
                i--;
            }
            if(j>=0){
                carry+=b[j]-'0';
                j--;
            }
            ans=to_string(carry%2)+ans;
            carry/=2;
        }
        return ans;
    }
};
