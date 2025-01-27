// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<vector<int>> adj(numCourses);

//         for(auto &edge: prerequisites) {
//             adj[edge[0]].push_back(edge[1]);
//         }

//         vector<vector<bool>> isReachable(numCourses, vector<bool> (numCourses, false));

//         vector<bool> vis(numCourses, false);


//         for(int i=0; i<numCourses; i++) {
//             queue<int> q;
//             q.push(i);

//             while(!q.empty()) {
//                 auto n = q.size();

//                 while(n--) {
//                     auto top = q.front();
//                     q.pop();


//                     isReachable[i][top] = true;

//                     for(auto next: adj[top]) {
//                         if(vis[next] == false)
//                             q.push(next);
//                     }
//                 }
//             }
//             vis[i] = true;
//         }

//         vector<bool> ans;

//         for(auto q: queries) {
//             ans.push_back(isReachable[q[0]][q[1]]);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        unordered_map<int, unordered_set<int>> mp;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto next : adj[curr]) {
                mp[next].insert(curr);
                for(auto pre : mp[curr]) {
                    mp[next].insert(pre);
                }
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        vector<bool> res;
        for(auto q : queries) {
            res.push_back(mp[q[1]].count(q[0]));
        }
        return res;
    }
};
