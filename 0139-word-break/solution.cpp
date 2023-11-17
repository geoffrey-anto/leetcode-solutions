class Solution {
public:
    bool isPresent(vector<string> &x, string str) {
        return find(x.begin(), x.end(), str) != x.end();
    }
    bool solve(int idx,string s,vector<string>& wordDict,int prev,map<pair<int,int>,bool>&dp){
        if(idx>=s.length()) return true;
        if(idx==s.length()-1) return isPresent(wordDict, s.substr(prev+1,idx+1));
        if(dp.count({idx,prev})>0) return dp[{idx,prev}];

        for(int i=idx;i<s.length();i++){
            string str = s.substr(prev+1,i+1-prev-1);
            if(isPresent(wordDict, str)){
                return dp[{idx,prev}] = solve(i+1,s,wordDict,i,dp) or solve(i+1,s,wordDict,prev,dp);
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<pair<int,int>,bool> dp;
        return solve(0,s,wordDict,-1,dp);
    }
};
