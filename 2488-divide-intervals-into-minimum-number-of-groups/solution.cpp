class Solution {
public:
    int minGroups(vector<vector<int>>& v) {
        int n = v.size();
        
        sort(v.begin(), v.end());
       
        multiset<pair<int, int>> s;

        for (int i = 0; i < n; i++) {
            s.insert({v[i][0], v[i][1]});
        }
        
        int cnt = 0; 
        
        while (!s.empty()) {
            auto it = *s.begin();  
            auto it1 = s.begin();  
            s.erase(it1); 
            
            while (true) {
                auto next_it = s.upper_bound({it.second, INT_MAX});
                
                if (next_it == s.end()) {
                    break;
                }
              
                it = *next_it;
               
                s.erase(next_it);
            }
            
            cnt++;  
        }
        
        return cnt;
    }
};

