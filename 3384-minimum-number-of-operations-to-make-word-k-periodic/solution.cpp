class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        string buf;
        unordered_map<string, int> mp;
        
        int n = word.size();
        
        for(int i=0; i<n; i+=k) {
            string a = word.substr(i, k);
            mp[a]++;
        }
        
        int mx = 0;
        string ans = "";
        
        for(auto &[k, v]: mp) {
            if(v > mx) {
                mx = v;
                ans = k;
            }
        }
        
        return (n/k) - mx;
    }
};
