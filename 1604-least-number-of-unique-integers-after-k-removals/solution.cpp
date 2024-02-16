class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(auto &i: arr) {
            mp[i]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &[k, v]: mp) {
            pq.push(v);
        }

        mp.clear();

        while(true) {
            if(pq.top() > k) {
                break;
            }

            k = k - pq.top();
            pq.pop();
        }

        return pq.size();
    }
};
