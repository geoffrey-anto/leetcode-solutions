class Solution {
public:
    bool chk(int n) {
        if (n == 0)
            return false;
    
        if (((n + 1) & n) == 0)
            return true;
    
        return false;
    }

    bool check(string &s, unordered_map<string, int> &f, int &w) {
        for(int i=0; i<s.size(); i+=w) {
            string temp = s.substr(i, w);

            if(f.find(temp) != f.end()) {
                if(f[temp] == 0) {
                    return false;
                }

                f[temp]--;
            } else {
                return false;
            }
        }

        return true;
    }

    vector<int> findSubstring(string &s, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = s.size();
        int m = words.size();
        int w = words[0].size();

        int l = w * m;

        string curr = "";

        // for(int i=0; i<l-1; i++) {
        //     curr += s[i];
        // }

        unordered_map<string, int> f;

        vector<int> ans;

        for(auto &i: words) {
            f[i]++;
        }

        unordered_map<string, int> mem = f;

        for(int i=0; i <= n - l; i++) {
            string st = s.substr(i, l);
            if(check(st, f, w)) {
                ans.push_back(i);
            }
            f = mem;
        }

        return ans;
    }
};  
