class Solution {
public:
    bool isValid(vector<vector<int>> &a, long long m) {
        for(auto &i: a) {
            if(m >= i[0]) {
                m += -i[0] + i[1];
            } else {
                // not possible to proceed
                return false;
            }
        }

        return true;
    }
    long long minimumMoney(vector<vector<int>>& t) {
        // there can be 2 parts where cost > cash or cash > cost;
        vector<vector<int>> a, b;
        long long sum = 0;

        for(auto &i: t) {
            if(i[0] > i[1]) {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
            sum += i[0];
        }

        // More cost than cashback
        // sort by decending order of cashback
        sort(begin(a), end(a), [&](auto &a, auto &b) {
            if(a[1] == b[1]) {
                return a[0] > b[0];
            }

            return a[1] < b[1];
        });

        // more cashback than cost
        // sort by cost
        sort(begin(b), end(b), [&](auto &a, auto &b) {
            return a[0] > b[0];
        });

        // join vectors
        a.insert(a.end(), b.begin(), b.end());

        long long l = 0;
        long long r = sum;

        long long ans = 0;

        // lowebound
        while(l <= r) {
            long long m = (l + r) / 2;

            if(isValid(a, m)) {
                ans = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }

        return ans;
    }
};
