class Solution {
public:
    
    void f(vector<string> &board,int col ,vector<int> &left , vector<int> &lower, vector<int> &upper, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(left[i]!=1 and lower[i+col]!=1 and upper[n-1 + col - i]!=1){
                left[i]=1;
                lower[i+col]=1;
                upper[n-1 + col - i]=1;
                board[i][col]='Q';
                f(board,col+1,left,lower,upper,ans,n);
                left[i]=0;
                lower[i+col]=0;
                upper[n-1 + col - i]=0;
                board[i][col]='.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        vector<int> leftRow(n, 0), lowerDiagonal(2*n -1, 0), upperDiagonal(2*n -1);
        vector<vector<string>> ans;
        f(board,0,leftRow,lowerDiagonal,upperDiagonal,ans,n);
        return ans;
    }
};