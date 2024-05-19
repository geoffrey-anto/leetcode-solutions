class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        vector<vector<int>> mp1(9, vector<int>(9, 0)), mp2(9, vector<int>(9, 0)), mp3(9, vector<int>(9, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '.') {
                    continue;
                }

                int k = (((i / 3) * 3) + (j / 3));

                if(mp1[i][board[i][j] - '0' - 1]) {
                    return false;
                }

                if(mp2[j][board[i][j] - '0' - 1]) {
                    return false;
                }

                if(mp3[k][board[i][j] - '0' - 1]) {
                    return false;
                }

                mp1[i][board[i][j] - '0' - 1] = 1;
                mp2[j][board[i][j] - '0' - 1] = 1;
                mp3[k][board[i][j] - '0' - 1] = 1;
            }
        }

        return true;
    }
};
