class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto &i: points) {
            pq.push({i[0], i[1]});
        }
                
        int ans = 0;
        
        while(!pq.empty()) {           
            auto curr = pq.top();
            pq.pop();
            
            ans++;
            
            while(!pq.empty() && (pq.top().first - curr.first) <= w) {
                pq.pop();
            }
        }
        
        return ans;
    }
};
