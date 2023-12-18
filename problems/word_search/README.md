# Word Search

## Leetcode Link: [Word Search](https://leetcode.com/problems/word-search/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};

    bool solve(int x, int y, vector<vector<char>>& board, string word, vector<vector<bool>> &vis, string ans) {
        if(word.length() < ans.length()) return false;
        if(word == ans) {
            return true;
        }

        if((x < 0 or x >= board.size()) or (y < 0 or y >= board[0].size())) {
            return false;
        }

        if(vis[x][y] == true) {
            return false;
        }

        vis[x][y] = true;
        bool res = false;
        for(auto i = 0; i < 4; i++) {
            if(res) return true;
            if(board[x][y] == word[ans.length()])
                res = solve(x + dx[i], y + dy[i], board, word, vis, ans + board[x][y]);

        }

        vis[x][y] = false;

        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (solve(i, j, board, word, vis, ""))
                    return true;



        return false;
    }
};```



