class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isSafe(board,i,j,ch)){
                            board[i][j] = ch;
                            if((solve(board))){
                                return true;
                            } else {
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isSafe(vector<vector<char>> &board, int i, int j, char c){
        for(int idx=0;idx<9;idx++){
            if(board[idx][j]==c){
                return false;
            }
            if(board[i][idx]==c){
                return false;
            }
            if(board[3*(i/3)+idx/3][3*(j/3)+idx%3] == c){
                return false;
            }
        }
        return true;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
