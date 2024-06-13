class Solution {
public:
    int f(vector<int> s, int k) {
        int n = s.size();
        unordered_map<int, int> mp;

        int ans = 0;

        int l = 0, m = 0;

        for(int i=0; i<n; i++) {
            mp[s[i]] ++;

            while(mp.size() > k) {
                mp[s[l]]--;
                if(mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }

            ans = max(ans, i - l + 1);
        }

        return ans;
    }

    int totalFruit(vector<int>& fruits) {
        return f(fruits, 2);
    }
};
