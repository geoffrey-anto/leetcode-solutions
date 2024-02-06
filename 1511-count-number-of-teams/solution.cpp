class Solution {
public:
    int dp[1001][3][3];

    int DK = 0;
    int INC = 1;
    int DEC = 2;

    int f(int idx, int c, vector<int>& rating, int n, int turn) {
        if(c == 3) {
            return 1;
        }

        if(idx == n) {
            return 0;
        }

        if(dp[idx][c][turn] != -1) {
            return dp[idx][c][turn];
        } 


        int take = 0;

        int prev = rating[idx];

        for(int i=idx+1; i<n; i++) {
            if(turn == INC) {
                if(prev < rating[i]) {
                    take += f(i, c+1, rating, n, INC);
                }
            } else if(turn == DEC) {
                if(prev > rating[i]) {
                    take += f(i, c+1, rating, n, DEC);
                }
            } else if(turn == DK) {
                if(prev > rating[i]) {
                    take += f(i, c+1, rating, n, DEC);
                } else if(prev < rating[i]) {
                    take += f(i, c+1, rating, n, INC);
                }
            }
        }


        return dp[idx][c][turn] = (take);
    }
    int numTeams(vector<int>& rating) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        
        for(int i=0; i<=rating.size()-3; i++) {
            ans += f(i, 1, rating, rating.size(), DK);
        }

        return ans;
    }
};
