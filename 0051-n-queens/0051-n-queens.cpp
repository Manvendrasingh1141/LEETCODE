class Solution {
public:
    // bool check(int n,int row,int col,vector<string>&board){
    //     int i=row,j=col;

    //     while(i>-1 && j>-1){
    //         if(board[i][j]=='Q')return 0;
    //         i--;
    //         j--;
    //     }

    //     i=row , j=col;
    //     while(i>-1 && j<n){
    //         if(board[i][j]=='Q')return 0;
    //         i--;
    //         j++;
    //     }

    //     return 1;
    // }

    void fun(int row,int n,vector<bool>&col, vector<bool>&leftDiagonal, vector<bool>&rightDiagonal,
    vector<vector<string>>&ans,vector<string>&board){
        if(row==n){
            ans.push_back(board);
            return;
        }
        /*
        leftDiagonal  : (n-1)+(col-row)
        rightDiagonal : col+row
        */
        for(int j=0;j<n;j++){
            if(!col[j] && !leftDiagonal[n-1+j-row] && !rightDiagonal[row+j]){
                col[j]=1;
                leftDiagonal[n-1+j-row]=1;
                rightDiagonal[row+j]=1;
                board[row][j] = 'Q';

                fun(row+1,n,col,leftDiagonal,rightDiagonal,ans,board);

                board[row][j] = '.';
                leftDiagonal[n-1+j-row]=0;
                rightDiagonal[row+j]=0;
                col[j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        board[i].push_back('.');

        vector<bool>col(n,0);

        vector<bool>leftDiagonal(2*n-1,0);
        vector<bool>rightDiagonal(2*n-1,0);
        fun(0,n,col,leftDiagonal,rightDiagonal,ans,board);

        return ans;
    }
};