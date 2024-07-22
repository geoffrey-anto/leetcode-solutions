class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        vector<int> ids(n, 0);

        iota(begin(ids), end(ids), 0);

        sort(begin(ids), end(ids), [&] (const int a, const int b) {
            return heights[a] > heights[b];
        });

        vector<string> ans;

        for(auto i: ids) {
            ans.push_back(names[i]);
        }

        return ans;
    }
};  
