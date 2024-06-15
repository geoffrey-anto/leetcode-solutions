class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<int> sc(n, 0);

        iota(begin(sc), end(sc), 0);

        sort(begin(sc), end(sc), [&capital](const int& a, const int& b) {
            return capital[a] < capital[b];
        });

        int i = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

        while(i < n and capital[sc[i]] <= w) {
            pq.push({profits[sc[i]], capital[sc[i]]});
            i++;
        }

        while(k > 0 and !pq.empty()) {
            auto t = pq.top();
            pq.pop();

            w += t.first;

            while(i < n and capital[sc[i]] <= w) {
                pq.push({profits[sc[i]], capital[sc[i]]});
                i++;
            }

            k--;
        }

        int ans = w;

        return ans;
    }
};
