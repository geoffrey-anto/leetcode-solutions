# String Compression

## Leetcode Link: [String Compression](https://leetcode.com/problems/string-compression/)
### Language: C++

```cpp
class Solution {
public:
    string getCompressedString(string s, int n) {
        string res = "";
        // res += s[0];
        int cnt = 1;
        for(auto i=1; i<n; i++) {
            if(s[i] == s[i-1]) {
                cnt++;
            } else {
                if(cnt == 0) {
                    res += s[i];
                } else {
                    if(cnt == 1) {
                        res += s[i - 1];
                        continue;
                    }
                    res += s[i-1] + to_string(cnt);
                    cnt = 1; 
                }
            }
        }

        if(cnt != 0) {
            if(cnt == 1) {
                res += s[n - 1];
            } else {
                res += s[n-1] + to_string(cnt);
            }
        }

        return res;
    }

    int compress(vector<char>& chars) {
        string s = "";

        for(auto &i: chars) {
            s += i;
        }



        s = getCompressedString(s, s.length());

        chars.clear();

        for(auto i: s) {
            chars.push_back(i);
        }

        return s.size();
    }
};```



