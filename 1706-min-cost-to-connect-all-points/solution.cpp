class Solution {
    int DEBUG = false;
    
public:
    int manhattanDistance(pair<int, int> p1, pair<int, int> p2) {
        return abs( abs(p1.first - p2.first) + abs(p1.second - p2.second) );
    }

    int getMST(map<pair<int, int>, vector<pair<int ,pair<int, int>>>> &adj, pair<int, int> &start) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        map<pair<int, int>, bool> vis;

        pq.push(make_pair(0, start));

        int sum = 0;

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int dis = top.first;
            auto n = top.second;

            if(vis[n] == true) {
                continue;
            }

            vis[n] = true;

            sum += dis;

            for(auto &node: adj[n]) {
                if(!vis[node.second]) {
                    pq.push(make_pair(node.first, node.second));
                }
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int, int>, vector<pair<int ,pair<int, int>>>> adj;

        for(auto &i: points) {
            adj[make_pair(i[0], i[1])] = vector<pair<int ,pair<int, int>>>();
        }

        for(auto &i: adj) {
            for(auto &j: adj) {
                if(i != j) {
                    i.second.push_back({manhattanDistance(i.first, j.first) ,j.first});
                }
            }
        }

        auto start = make_pair(points[0][0], points[0][1]);

        return getMST(adj, start);
    }
};
