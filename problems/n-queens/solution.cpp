class Solution {
public:
    void f(
        int col, 
        vector<string> &board, 
        vector<vector<string>> &ans, 
        int n,
        vector<bool> &colChk,
        vector<bool> &upDiag,
        vector<bool> &downDiag
    ) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n;row++) {
            if(colChk[row] == false && upDiag[n-1 + col - row] == false && downDiag[row+col] == false) {
                board[row][col]='Q';
                colChk[row] = true;
                upDiag[n-1+col-row] = true;
                downDiag[row+col] = true;
                f(col+1, board, ans, n, colChk, upDiag, downDiag);
                board[row][col]='.';
                colChk[row] = false;
                upDiag[n-1+col-row] = false;
                downDiag[row+col] = false;
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