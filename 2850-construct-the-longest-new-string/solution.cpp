// enum Type { AA, BB, AB };

// class Solution {
// public:
//     int f(Type prev, int x, int y, int z, vector<vector<vector<vector<int>>>> &dp) {
//         int ans = 0;

//         if(dp[x][y][z][prev] != -1) {
//             return dp[x][y][z][prev];
//         }

//         switch(prev) {
//             case AA:
//                 if(y != 0) {
//                     ans = max(ans, 2 + f(BB, x, y-1, z, dp));
//                 }
//             break;
//             case BB:
//                 if(x != 0) {
//                     ans = max(ans, 2 + f(AA, x-1, y, z, dp));
//                 }
//                 if(z != 0) {
//                     ans = max(ans, 2 + f(AB, x, y, z-1, dp));
//                 }
//             break;
//             case AB:
//                 if(x != 0) {
//                     ans = max(ans, 2 + f(AA, x-1, y, z, dp));
//                 }
//             break;
//         }

//         return dp[x][y][z][prev] = ans;
//     }

//     int longestString(int x, int y, int z) {
//         int ans = 0;
//         vector<vector<vector<vector<int>>>> dp(x+1, vector<vector<vector<int>>>(y+1, vector<vector<int>> (z+1, vector<int>(3, -1))));

//         ans = max(ans, 2 + f(AA, x-1, y, z, dp));
//         ans = max(ans, 2 + f(BB, x, y-1, z, dp));
//         ans = max(ans, 2 + f(AB, x, y, z-1, dp));

//         return ans;
//     }
// };

class Solution {
public:
    int longestString(int x, int y, int z) {
        // we can do a interweawing pattern with x and y
        // we can also insert z in between

        // |BB AB AA| |BB AB AA|

        // 2 * min(x, y) + z + (1 extra pair of maxElementOf(x,y));
        // No extra pair if x == y

        int ans = 0;
        ans = (2*min(x, y)) + z + 1;

        ans -= (x == y);

        return ans * 2;
    }
};
