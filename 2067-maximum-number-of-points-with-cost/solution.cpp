class Test {
public:
    long long f(int i, int j, vector<vector<int>>& points, vector<vector<long long>> &dp) {
        if(i == points.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        long long ans = 0;

        for(int k=0; k<points[0].size(); k++) {
            long long curr = points[i][k] + f(i+1, k, points, dp);
            
            if(j != -1) {
                ans = max(ans, curr - abs(k - j));
            } else {
                ans = max(ans, curr);
            }
        }

        return dp[i][j] = ans;
    }

    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(); int m = points[0].size();
        vector<long long> prev(m+2, 0);
        for(int i=n-1; i>=0; i--) {
            vector<long long> curr(m+2, 0);
            for(int j=m-1; j>=0; j--) {
                long long ans = 0;

                for(int k=0; k<points[0].size(); k++) {
                    long long curr = points[i][k] + prev[k];
                    
                    if(j != -1) {
                        ans = max(ans, curr - abs(k - j));
                    } else {
                        ans = max(ans, curr);
                    }
                }

                curr[j] = ans;
            }
            prev = curr;
        }

        long long ans = 0;

        for(int i=0; i<m; i++) {
            ans = max(ans, prev[i]);
        }

        return ans;
    }
};

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(); int m = points[0].size();

        vector<long long> dp(m, 0);
        for(int j=0; j<m; j++) {
            dp[j] = points[0][j];
        }

        for(int i=1; i<n; i++) {
            vector<long long> dp_next(m, 0);

            for(int j=0; j<m; j++) {
                dp_next[j] = points[i][j];
            }

            vector<long long> left(m, 0ll), right(m, 0ll);

            left[0] = dp[0];

            for(int j=1; j<m; j++) {
                left[j] = max(dp[j], left[j-1] - 1);
            }

            right[m - 1] = dp[m - 1];

            for(int j = m - 2; j >= 0; j--) {
                right[j] = max(dp[j], right[j+1] - 1);
            }
            
            for(int j=0; j<m; j++) {
                dp_next[j] += max(left[j], right[j]);
            }

            dp = dp_next;
        }

        return *max_element(begin(dp), end(dp));
    }
};
