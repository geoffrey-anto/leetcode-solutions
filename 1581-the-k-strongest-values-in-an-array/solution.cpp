class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int m = 0;
        int n = arr.size();
        sort(begin(arr), end(arr));

        m = arr[(n-1) / 2];

        sort(begin(arr), end(arr), [&](const int& a, const int& b) {
            if(abs(a - m) == abs(b - m)) {
                return a > b;
            } else {
                return abs(a - m) > abs(b - m);
            }
        });

        vector<int> ans;

        for(auto i: arr) {
            if(k == 0) {
                break;
            }
            ans.push_back(i);
            k--;
        }

        return ans;
    }
};
