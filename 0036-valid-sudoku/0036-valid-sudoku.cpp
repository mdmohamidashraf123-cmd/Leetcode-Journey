class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        //check for each row
        for(int i=0;i<r;i++){
            int  hash[127]={0};
            for(int j=0;j<c;j++){
                if(board[i][j]!='.'){
                 if(hash[board[i][j]]>0){
                    return false;
                 }
                 hash[board[i][j]]++;
                }
            }
        }
        //check for each column
        for(int i=0;i<c;i++){
            int hash[127]={0};
            for(int j=0;j<r;j++){
              if(board[j][i]!='.'){
                if(hash[board[j][i]]>0){
                    return false;
                }
                hash[board[j][i]]++;
              }
            }
        }
        //check for each 3*3 boxes
        for(int i=0;i<r;i+=3){
            for(int j=0;j<r;j+=3){
             int hash[127]={0};
             for(int k=i;k<i+3;k++){
                for(int x=j;x<j+3;x++){
                    if(board[k][x]!='.'){
                    hash[board[k][x]]++;
                    if (hash[board[k][x]]>1){
                        return false;
                    }
                    }
                }
             }
            }
        }
        return true;
    }
};