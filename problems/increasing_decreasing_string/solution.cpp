// class Solution {
// public:
//     string sortString(string s) {
//         string ans;
//         map<char,int> mp;
//         for(auto chr:s){
//             mp[chr]++;
//         }
//         bool fst=false;
//         while(!mp.empty()){
//         fst=!fst;
//         string temp;
//         for(auto &pt:mp){
//             if(pt.second>0 and fst){
//                 ans+=pt.first;
//                 pt.second--;
//             } else if(pt.second > 0 and !fst){
//                 temp+=pt.first;
//                 pt.second--;
//             } else {
//                 mp.erase(pt.first);
//             }
//          }
//             reverse(temp.begin(),temp.end());
//             ans=ans+temp;
//             temp="";
//         }
//         return ans;
//     }
// };
class Solution {
public:
    string sortString(string s) {
        string res="";
        int a[26]={0},k=0;
        for(int i=0;i<s.length();i++)
        {
            a[s[i]-'a']++;
            k++;
        }
        while(k)
        {
            for(int i=0;i<26;i++)
            {
                if(a[i]>0) { res+=i+'a';k--;a[i]--;}
            }
            for(int i=25;i>=0;i--)
            {
                if(a[i]>0) { res+=i+'a';k--;a[i]--;}
            }
        }
        return res;      
    }
};