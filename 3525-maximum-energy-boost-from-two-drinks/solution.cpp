#define ll long long

class Solution {
public:
    ll f(int i, bool j, vector<vector<int>>& drinks, int n, vector<vector<ll>> &dp) {
        if(i == n) {
            return 0ll;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        ll ans = 0;

        ans = max(ans, drinks[j][i] + f(i+1, j, drinks, n, dp));
        ans = max(ans, f(i+1, !j, drinks, n, dp));

        return dp[i][j] = ans;
    }

    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        vector<vector<int>> drinks;
        drinks.push_back(energyDrinkA);
        drinks.push_back(energyDrinkB);
        
        vector<vector<ll>> dp(energyDrinkA.size(), vector<ll>(3, -1ll));

        return max(f(0, 0, drinks, energyDrinkA.size(), dp), f(0, 1, drinks, energyDrinkA.size(), dp));
    }
};
