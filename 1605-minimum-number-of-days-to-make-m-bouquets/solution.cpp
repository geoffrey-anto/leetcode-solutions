class Solution {
public:
    bool f(vector<int>& bloomDay, int m, int k, int v) {
        int n = bloomDay.size();
        int cnt = 0;
        for(int i: bloomDay) {
            if(i <= v) {
                cnt++;

                if(cnt == k) {
                    m--;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }

        return m <= 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if ((long long)m * (long long)k > (long long)n) {
            return -1;
        } 

        int mx = *max_element(begin(bloomDay), end(bloomDay));
        int mn = *min_element(begin(bloomDay), end(bloomDay));

        int l = mn;
        int r = mx;

        while(l <= r) {
            int md = (l + r) / 2;

            if(f(bloomDay, m, k, md)) {
                r = md - 1;
            } else {
                l = md + 1;
            }
        }

        return l;
    }
};
