class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int ans = 0;

        int n = apples.size();

        for(int i=0; i<n; i++) {
            if(apples[i]) {
                pq.push({
                    days[i] + i, apples[i]
                });
            }

            while(!pq.empty() and pq.top().first <= i) {
                pq.pop();
            }

            if(!pq.empty()) {
                ans += 1;

                auto t = pq.top();
                pq.pop();

                if(t.second-1 != 0) {
                    pq.push({t.first, t.second-1});
                }
            } else {
                ans += 0;
            }
        }

        int i = n;

        while(!pq.empty()) {
            while(!pq.empty() and pq.top().first <= i) {
                pq.pop();
            }

            if(!pq.empty()) {
                ans += 1;

                auto t = pq.top();
                pq.pop();
                
                if(t.second-1 != 0) {
                    pq.push({t.first, t.second-1});
                }
            } else {
                ans += 0;
            }
            
            i++;
        }

        return ans;
    }
};
