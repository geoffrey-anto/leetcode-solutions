class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        queue<int> q;

        auto keysInStart = rooms[0];

        vector<int> vis(n, 0);

        for(auto &key: keysInStart) {
            q.push(key);
            vis[key] = 1;
        }

        vis[0] = 1;


        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            vis[t] = 1;
            for(auto i: rooms[t]) {
                if(!vis[i]) {
                    q.push(i); 
                }
            }
        }

        for(auto &i: vis) {
            cout << i << endl;
            if(i == 0) {
                return false;
            }
        }

        return true;
    }
};
