class Solution {
public:
    int find(string &s,char k){
        for(int i=0;i<s.size();i++){
            if(s[i]==k) return i;
        }
        return 0;
    }
    int firstUniqChar(string s) {
        // int c = 0;

        // for(auto &i: s) {
        //     if(count(begin(s), end(s), i) == 1) {
        //         return c;
        //     }
        //     c++;
        // }

        // return -1;

        unordered_map<char,int>ans;

        for(int i=0;i<s.size();i++){
            ans[s[i]]++;
        }

        for(int i=0; i<s.size(); i++) {
            if(ans[s[i]] == 1) return i;
        }
        
        return -1;
    }
};
