class Solution {
public:

    bool check(int num,int r,int c,vector<vector<char>>& board){
        //row
        for(int i=0;i<9;i++){
            if(board[r][i]=='0'+num)return 0;
        }
        //col
        for(int i=0;i<9;i++){
            if(board[i][c]=='0'+num)return 0;
        }
        //cell
        int row = r/3*3 , col=c/3*3;
        for(int i=row;i<row+3;i++)
        for(int j=col;j<col+3;j++)
        if(board[i][j]=='0'+num)return 0;



        return 1;
    }

    bool fun(int i,int j,vector<vector<char>>& board){
        //base condition
        if(i==9)return 1;

        //when reaches to j=9 go to new row(i==0)
        if(j==9)return fun(i+1,0,board);

        if(board[i][j]!='.')return fun(i,j+1,board);

        for(int num=1;num<=9;num++){
            if(check(num,i,j,board)){
                board[i][j] = '0' + num;
                if(fun(i,j+1,board))return 1;
                board[i][j] = '.';
            }
        }

        return 0;

    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(0,0,board);
    }
};