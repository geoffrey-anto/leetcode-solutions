class Solution {
public:
    int dp[10003];

    int f(int x, int y) {
        if(x <= y) {
            return y - x;
        }

        if(x <= 0) {
            return 1e9;
        }

        if(dp[x] != -1) {
            return dp[x];
        }

        int a = 1e9;
        int b = 1e9;

        if(x % 11 == 0)  {
            b = 1 + f(x / 11, y);
        } else {
            b = ((11-(x%11))) + 1 + f((x + (11-(x%11)))/11, y);
        }

        if(x % 5 == 0) {
            a = 1 + f(x / 5, y);
        } else {
            a = ((5-(x%5))) + 1 + f((x + (5-(x%5)))/5, y);
        }

        int d = 1 + f(x - 1, y);

        return dp[x] = min(a, min(b, d));
    }


    int minimumOperationsToMakeEqual(int x, int y) {
        memset(dp, -1, sizeof(dp));
        return f(x, y);
    }
};
