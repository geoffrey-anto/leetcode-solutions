// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) {
//         // O(n) -> O(nlogn)
//         int mn = INT_MAX, mx = INT_MIN;

//         for(auto &i: arrays) {
//             int currMn = i[0];
//             int currMx = i[i.size() - 1];

//             if(mn == INT_MAX or mx == INT_MIN) {
//                 mn = min(mn, currMn);
//                 mx = max(mx, currMx);
//                 continue;
//             }

//             if(mn > currMn and mx < currMx) {
//                 if(mn - currMn > mx - currMx) {
//                     mn = currMn;
//                 } else {
//                     mx = currMx;
//                 }
//             } else {
//                 mn = min(mn, currMn);
//                 mx = max(mx, currMx);
//             }

//         }

//         return abs(mx - mn);
//     }
// };

// // 3 1                        12 10

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            max_distance = max(max_distance, abs(arrays[i].back() - smallest));
            max_distance = max(max_distance, abs(biggest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }

        return max_distance;
    }
};
