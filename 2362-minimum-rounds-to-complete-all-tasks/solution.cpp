class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;

        for(auto &i: tasks) {
            mp[i]++;
        }

        int ans = 0;

        for(auto &[k, v]: mp) {
            if(v == 1) {
                return -1;
            } 

            int m = (v+2) / 3;

            // cout << v << " " << m << endl;

            ans += (m);
        }

        return ans;
    }
};
