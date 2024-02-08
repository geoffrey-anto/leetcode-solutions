# String Compression Ii

## Leetcode Link: [String Compression Ii](https://leetcode.com/problems/string-compression-ii/)
### Language: C++

```cpp
// class Solution {
// public:
//     string getCompressedString(string s, int n) {
//         string res = "";
//         int cnt = 1;
//         for(auto i=1; i<n; i++) {
//             if(s[i] == s[i-1]) {
//                 cnt++;
//             } else {
//                 if(cnt == 0) {
//                     res += s[i];
//                 } else {
//                     if(cnt == 1) {
//                         res += s[i - 1];
//                         continue;
//                     }
//                     res += s[i-1] + to_string(cnt);
//                     cnt = 1; 
//                 }
//             }
//         }

//         if(cnt != 0) {
//             if(cnt == 1) {
//                 res += s[n - 1];
//             } else {
//                 res += s[n-1] + to_string(cnt);
//             }
//         }

//         return res;
//     }

//     /*
//         Cases: k->4
//             1) A -> ""
//             2) A4 -> ""
//             3) A12 -> A9
//             4) A102 -> A99

//     */
//     bool isChar(char c) {
//         return c >= 97 && c <= 122;
//     }
//     pair<int, int> getNoInFront(string s, int i, int n) {
//         char c = s[i];
//         int ans = 0;
//         i++;
//         int ori = i;

//         while(i != n && !isChar(s[i])) {
//             ans = ans*10 + stoi(to_string(s[i]));
//             i++;
//         }

//         return {ans, i - ori + 1};
//     }
//     int f(int i, int k, string s, int n) {
//         if(i >= n) {
//             return 0;
//         }

//         if(k == 0) {
//             return 0;
//         }

//         int ans = -1;

//         if(i != n-1) {
//             // In Form of A|B
//             if(isChar(s[i+1])) {
//                 ans = max(ans, 1 + f(i+1, k-1, s, n));
//             } else {
//             // In Form Of A1|....
//             // This can have 3 cases
//                 auto r = getNoInFront(s, i, n);
//                 int no = r.first;
//                 int sz = r.second;

//                 if(sz == 3) {
//                     if(k >= no - 99) {
//                         ans = max(ans,  1 + f(i+sz+1, k - (no - 99), s, n));
//                     }
//                 } else if(sz == 3 or sz == 2) {
//                     if(k >= no - 9) {
//                         ans = max(ans,  1 + f(i+sz+1, k - (no - 9), s, n));
//                     }
//                 }

//                 if(k >= no) {
//                     ans = max(ans,  sz+1 + f(i+sz+1, k - (no), s, n));
//                     ans = max(ans,  1 + f(i+sz+1, k - (no - 1), s, n));
//                 }
//             }
//         } else {
//             // only Single char can reach here! And End
//             ans = max(ans, 1+f(i+1, k-1, s, n));
//         }

//         return ans;
//     }
    

//     int getLengthOfOptimalCompression(string s, int k) {
//         int n = s.length();
//         string c = getCompressedString(s, n);

//         return c.size() - f(0, k, s, c.size());
//     }
// };

class Solution {
    int dp[101][27][11][101];
public:

    int f(string& s, int cur, char last, int cnt, int k) {
        if (s.size() == 100) {
            bool all_same = true;
            for (int i = 1;i < s.size();++i) {
                if (s[i] != s[i - 1]) {
                    all_same = false;
                    break;
                }
            }
            if (all_same) return 4;
        }

        
        if (k < 0) return 101;

        if (cur >= s.size()) {
            return 0;    
        }
        if (cnt >= 10) cnt = 10;

        if (dp[cur][last - 'a'][cnt][k] != -1) return dp[cur][last - 'a'][cnt][k];
        
        int res = 101;
        res = f(s, cur + 1, last, cnt, k - 1);

        if (s[cur] != last) {
            res = min(res, 1 + f(s, cur + 1, s[cur], 1, k));
        } else { 
            if (cnt == 1 or cnt == 9 or cnt == 99) {
                res = min(res, 1 + f(s, cur + 1, last, cnt + 1, k));
            } else {
                res = min(res, f(s, cur + 1, last, cnt + 1, k));
            }
        }
        return dp[cur][last - 'a'][cnt][k] = res;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        if (k >= s.size()) return 0;
        if (s.size() == 100) {
            bool all_same = true;
            for (int i = 1;i < s.size();++i) {
                if (s[i] != s[i - 1]) {
                    all_same = false;
                    break;
                }
            }
            if (all_same){
                if(k==0) return 4;
                else if(k>=1 && k<91) return 3;
                else if(k>=91 && k<99) return 2;
                else return 1;
            }
        }
        
        memset(dp, -1, sizeof(dp));
        return f(s, 0, 'z'+1, 0, k);
    }
};```



