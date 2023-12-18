class Solution {
public:
    bool isValid(int row, int i, int n, vector<bool> &colChk, vector<bool> &upDiag, vector<bool> &downDiag) {
        return colChk[row] == false && upDiag[n-1 + i - row] == false && downDiag[row+i] == false;
    }
    void f(int i, vector<string> &board, vector<vector<string>> &ans, int n, vector<bool> &colChk, vector<bool> &upDiag, vector<bool> &downDiag) {
        if(i == n) {
            ans.push_back(board);
        }

        for(int row=0; row<n;row++) {
            if(isValid(row, i, n, colChk, upDiag, downDiag)) {
                board[row][i] = 'Q';
                colChk[row] = true;
                upDiag[n-1 + i - row] = true;
                downDiag[row+i] = true;
                f(i+1, board, ans, n, colChk, upDiag, downDiag);
                board[row][i] = '.';
                colChk[row] = false;
                upDiag[n-1 + i - row] = false;
                downDiag[row+i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> colChk(n,false);
        vector<bool> upDiagChk((2*n) - 1, false);
        vector<bool> downDiagChk((2*n) - 1, false);
        f(0, board, ans, n, colChk, upDiagChk, downDiagChk);
        return ans;
    }
};