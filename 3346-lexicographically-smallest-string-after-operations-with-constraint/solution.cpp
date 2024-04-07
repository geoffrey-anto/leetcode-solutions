class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        
        string t = "";
        
        for(auto ch: s){
            if(k <= 0) {
                t += ch;
                continue;
            }
            int right = (ch - 'a');
            int left = ('z' - ch)+1;
            
            int currDist = min(right, left);
            
            if(currDist > k) {
                t += (ch - k);
                k = 0;
                continue;
            }
            
            t += 'a';
            k = k - currDist;
        }
        
        return t;
    }
};
