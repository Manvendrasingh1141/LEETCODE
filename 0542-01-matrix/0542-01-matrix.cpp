class Solution {
public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,1,-1};

    bool valid(int i,int j,int m,int n){
        return i>=0&&j>=0&&i<m&&j<n;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // {i,j}
        queue<pair<int,int>>q;
        for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            if (mat[i][j]==0)q.push({i, j});
            else mat[i][j] = -1; // Mark as unvisited
            }

       
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int r = i+row[k];
                int c = j+col[k];
                if(valid(r,c,m,n) && mat[r][c]==-1){
                    mat[r][c] = mat[i][j]+1;
                    q.push({r,c});
                }
            }            
        }

        return mat;
    }
};



//nearest zero to all the cell 
//weight is 1 
// bfs appyyy {DFS -> time increase}