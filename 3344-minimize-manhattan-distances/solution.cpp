class Solution {
public:
// //     int manhattanDistance(vector<int> &a, vector<int> &b) {
        
// //     }
//     int dist(vector<vector<int>> &points) {
//         int minS = points[0][0] + points[0][1];
//         int maxS = minS;
        
//         int minD = points[0][0] - points[0][1];
//         int maxD = minD;
        
//         int n = points.size();
//         int x = 0;
//         int y = 0;
        
//         for(int i=1; i<n; i++) {
//             int t = points[i][0] + points[i][1];
//             int s = points[i][0] - points[i][1];
            
//             if(t > maxS) {
//                 maxS = t;
//                 x = i;
//             } else if(t < minS) {
//                 minS = t;
//                 x = i;
//             } if(s > maxD) {
//                 maxD = s;
//                 y = i;
//             } else if(s < minD) {
//                 minD = s;
//                 y = i;
//             }
//         }
        
//         return min(maxS - minS, maxD - minD);
//     }
//     int f(vector<vector<int>> &points, int mid) {
//         int minS = points[0][0] + points[0][1];
//         int maxS = minS;
        
//         int minD = points[0][0] - points[0][1];
//         int maxD = minD;
        
//         int n = points.size();
//         int x = 0;
//         int y = 0;
        
//         for(int i=1; i<n; i++) {
//             int t = points[i][0] + points[i][1];
//             int s = points[i][0] - points[i][1];
            
//             if(t > maxS) {
//                 maxS = t;
//                 x = i;
//             } else if(t < minS) {
//                 minS = t;
//                 x = i;
//             } if(s > maxD) {
//                 maxD = s;
//                 y = i;
//             } else if(s < minD) {
//                 minD = s;
//                 y = i;
//             }
//         }
        
//         return min(maxS - minS, maxD - minD) <= mid;
//     }
//     int minimumDistance(vector<vector<int>>& points) {
//         // sort(points.begin(), points.end())
        
//         int l = 0;
        
//         int r = dist(points);
        
        
//         while(l < r) {
//             int m = l + (r - l) / 2;
            
//             if(f(points, m)) {
//                 r = m;
//             } else {
//                 l = m + 1;
//             }
//         }
        
//         return l;
        
//     }

    int minimumDistance(vector<vector<int>>& points) {

        multiset<int> m, n;

        for(auto &i: points) {
            m.insert(i[0]-i[1]);
            n.insert(i[0]+i[1]);
        }

        int ans = INT_MAX;

        for(auto &i: points) {
            m.erase(m.find(i[0]-i[1]));
            n.erase(n.find(i[0]+i[1]));

            ans = min(ans, max(*m.rbegin() - *m.begin(), *n.rbegin() - *n.begin()));

            m.insert((i[0]-i[1]));
            n.insert((i[0]+i[1]));
        }

        return ans;
    }
};
