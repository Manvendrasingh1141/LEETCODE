class Solution {
public:
    void DFS(int node,vector<bool>&visited,vector<vector<int>>& mat){
        visited[node]=1;
        for(int j=0;j<mat.size();j++){
            if(mat[node][j]==1 && !visited[j]){
                DFS(j,visited,mat);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        int cnt=0;
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                DFS(i,visited,mat);
            }
        }
        return cnt;
    }
};