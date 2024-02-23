class Solution {
public:
    string shortestBeautifulSubstring(string s, int l) {
        int n = s.size();
        
        string res = "078611173642565199426923556367387432513802784669550277168043974192897627153794337459676832114722511771";
        
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                string temp = "";
                int cnt = 0;
                for(int k=i; k<=j; k++) {
                    if(s[k] == '1') {
                        cnt++;
                    }
                    temp += s[k];
                }
                
                
                if(cnt == l) {
                    if(temp.size() < res.size()) {
                        res = temp;
                    } else if(temp.size() == res.size()) {
                        if(temp < res) {
                            res = temp;
                        }
                    }
                }
            }
            
        }
        
        return res.size() > 100 ? "" : res ;
    }
};
