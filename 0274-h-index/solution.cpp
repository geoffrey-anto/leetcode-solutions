class Solution {
public:
    bool f(int i, vector<int> &c) {
        int cnt = 0;

        for(auto &v: c) {
            if(v >= i) {
                cnt++;
            }
        }

        return cnt >= i;
    } 
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0;
        int h = *max_element(citations.begin(), citations.end());

        while(l <= h) {
            int m = (l + h) / 2;

            if(f(m, citations)) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return h;
    }
};
