class Solution {
public:
    vector<int> d = {0, 1, 0, -1, 0};
    bool isValid(int i, int j, int n, int m) {
        return i>=0 && i<n && j>=0 && j < m;
    }
    void dfs(int i, int j, vector<vector<char>>& board) {
        if(!isValid(i, j, board.size(), board[0].size()) or board[i][j] != 'O') return;

        board[i][j] = 'G';

        for(int x=0; x<4; x++) {
            dfs(i+d[x], j+d[x+1], board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<m; i++) {
            if(board[0][i] == 'O') {
                dfs(0, i, board);
            }
            if(board[n-1][i] == 'O') {
                dfs(n-1, i, board);
            }
        }

        for(int i=0; i<n; i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if(board[i][m-1] == 'O') {
                dfs(i, m-1, board);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'G') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};