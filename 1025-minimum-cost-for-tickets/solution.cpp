// class Solution {
// public:
//     int f(int i, vector<int> &days, int day, int week, int month, int n) {
//         if(i >= n) {
//             return 0;
//         }

//         int next = (int)(upper_bound(begin(days), end(days), i + day) - begin(days));

//         int a = day + f(next, days, day, week, month, n);

//         next = (int)(upper_bound(begin(days), end(days), i + week) - begin(days));

//         int b = week + f(next, days, day, week, month, n);

//         next = (int)(upper_bound(begin(days), end(days), i + month) - begin(days));

//         int c = month + f(next, days, day, week, month, n);

//         return min(a, min(b, c));
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int day = costs[0];
//         int week = costs[1];
//         int month = costs[2];

//         // maybe dp + bs

//         int n = days.size();

//         return f(0, days, day, week, month, n);
//     }
// };

class Solution {
public:
    int n;
    vector<int> dp; 
    
    int solve(int in, vector<int>& A, vector<int>& B) {
        if (in >= n) {
            return 0;
        }
        
        if (dp[in] != -1) {
            return dp[in];
        }
        
        int ans = INT_MAX;
        ans = min(ans, B[0] + solve(in + 1, A, B));
        
        int num = in;
        while (num < n && A[num] <= A[in] + 6) {
            num++;
        }
        ans = min(ans, B[1] + solve(num, A, B));
        
        int ij = in;
        while (ij < n && A[ij] <= A[in] + 29) {
            ij++;
        }
        ans = min(ans, B[2] + solve(ij, A, B));
        
        return dp[in] = ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.assign(n, -1);
        return solve(0, days, costs);
    }
};

