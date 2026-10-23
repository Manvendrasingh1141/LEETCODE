class Solution {
public:
    bool valid(int i,int j,int n,int m){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    int numIslands(vector<vector<char>>& grid) {
        /*
        apply bfs 
        check it's neighbour should not be visited & are valid
        */
        int N = grid.size();
        int M = grid[0].size();

        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,-1,1}; 
        int cnt=0;

        queue<pair<int,int>>q;
        for(int i=0;i<N;i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    grid[i][j] = '0';
                    cnt++;
                    
                    while(!q.empty()){
                    int i =  q.front().first;
                    int j =  q.front().second;
                    q.pop();
            
                    

                    for(int k=0;k<4;k++){
                        int r = row[k]+i;
                        int c = col[k]+j;
                        if(valid(r,c,N,M) && grid[r][c]=='1'){
                            q.push({r,c});
                            grid[r][c] = '0';
                        }
                    }
                }
            }
        }
    }
        return cnt;
    }
};