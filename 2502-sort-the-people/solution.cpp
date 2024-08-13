class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> i(names.size());

        iota(begin(i), end(i), 0);

        sort(begin(i), end(i), [&](int a, int b) {
            return heights[a] > heights[b];
        });

        vector<string> ans;

        for(auto j: i) {
            ans.push_back(names[j]);
        }

        return ans;
    }
};
