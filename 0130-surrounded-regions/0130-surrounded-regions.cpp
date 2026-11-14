class Solution {
public:
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,-1,1}; 

    bool isValid(int i,int j,int m,int n){
        return i>=0&&j>=0&&i<m&&j<n;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(board[i][j]=='O' && (i==0||j==0||i==m-1||j==n-1))q.push({i,j});

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int r = i + row[k];
                int c = j + col[k];
                if(isValid(r,c,m,n) && board[r][c]=='O'){
                    board[r][c] = 'T';
                    q.push({r,c});
                }
            }
        }

        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(board[i][j]=='O'){
                if(i==0||j==0||i==m-1||j==n-1)continue;
                else board[i][j]='X';
            }
            else if(board[i][j]=='T')board[i][j]='O';
        }
        
    }
};