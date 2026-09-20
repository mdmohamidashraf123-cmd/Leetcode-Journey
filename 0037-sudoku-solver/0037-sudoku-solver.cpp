class Solution {
public:
   bool issafe(vector<vector<char>>& board,int row,int col,char digit){
       for(int i=0;i<9;i++){
        if(board[row][i]==digit){
            return false;
        }
       }
       for(int i=0;i<9;i++){
        if(board[i][col]==digit){
            return false;
        }
       }
       int srow=(row/3)*3;
       int scol=(col/3)*3;
       for(int i=srow;i<srow+3;i++){
        for(int j=scol;j<scol+3;j++){
            if(board[i][j]==digit){
                return false;
            }
        }
       }
       return true;
    }
    bool helper(vector<vector<char>>& board,int row,int col){
        if(row==9){
            return true;
        }
        // if (board[row][col] != '.') {
        int nextRow = (col == 8) ? row + 1 : row;
        int nextCol = (col == 8) ? 0 : col + 1;
        // return helper(board, nextRow, nextCol);
        //  }
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }
       
        for(char dig='1';dig<='9';dig++){
            if(issafe(board,row,col,dig)){
            board[row][col]=dig;
            if(helper(board,nextRow,nextCol)){
                 return true;
            }
            board[row][col]='.';
            }     
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};