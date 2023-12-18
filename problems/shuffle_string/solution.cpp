class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<pair<int,char>> ans;
        for(int i=0;i<s.size();i++){
            ans.push_back(make_pair(indices[i],s[i]));
        }
        sort(ans.begin(),ans.end());
        string temp;
        for(auto [i,c]:ans){
            temp=temp+c;
        }
        return temp;
    }
};