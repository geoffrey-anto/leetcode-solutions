class Solution {
public:
    // tha dp or greedy
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;

        for(int i=0; i<nums1.size(); i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        sort(begin(v), end(v), [&](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        });


        priority_queue<int, vector<int>, greater<int>> pq;
        long long currS = 0;

        for(int i=0; i<k-1; i++) {
            pq.push(v[i].second);
            currS += v[i].second;
        }

        long long ans = 0ll;

        for(int i=k-1; i<nums1.size(); i++) {
            currS += v[i].second;
            pq.push(v[i].second);
            ans = max(ans, (long long)((long long)currS * (long long)v[i].first));
            currS -= pq.top();
            pq.pop();
        }

        return ans;
    }
};

