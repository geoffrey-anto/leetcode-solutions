// class Solution {
// public:
//     int f(vector<int> &arr, int A, int B, int turn) {
//         if(A>B) return 0;

//         // turn = 1 then alice else bob if 0

//         int res = 0;

//         if(turn == 1) {
//             int start = f(arr, A+1, B, 0) + arr[A];
//             int end = f(arr, A, B-1, 0) + arr[B];

//             return res = max(start, end);
//         } else {
//             int start = f(arr, A+1, B, 1) - arr[A];
//             int end = f(arr, A, B-1, 1) - arr[B];

//             return res = max(start, end);
//         }
//     }
//     bool stoneGame(vector<int>& piles) {
//         return f(piles, 0, piles.size()-1, 1);
//     }
// };

class Solution {
public:
    int f(vector<int> &arr, int A, int B, int turn, vector<vector<vector<int>>> &dp) {
        if(A>B) return 0;

        if(dp[turn][A][B] != -1) {
            cout << "HIT" <<endl;
            return dp[turn][A][B];
        }

        // turn = 1 then alice else bob if 0

        int res = 0;

        if(turn == 1) {
            int start = f(arr, A+1, B, 0, dp) + arr[A];
            int end = f(arr, A, B-1, 0, dp) + arr[B];

            return dp[turn][A][B] = res = max(start, end);
        } else {
            int start = f(arr, A+1, B, 1, dp) - arr[A];
            int end = f(arr, A, B-1, 1, dp) - arr[B];

            return dp[turn][A][B] = res = max(start, end);
        }
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(piles.size()+1, vector<int>(piles.size()+1, -1)));
        return f(piles, 0, piles.size()-1, 1, dp);
    }
};