class Solution {
public:

    bool DFS(int node ,int strt,int end, vector<bool>&visited , vector<vector<int>>&adj){
        visited[node] = 1;
        if(node == end)return 1;

        for(int j=0;j<adj[node].size();j++){
            if(!visited[adj[node][j]]){
                if(DFS(adj[node][j],strt,end,visited,adj))return 1;
            }
        }

        return 0;
    }
    bool validPath(int V, vector<vector<int>>& edges, int strt, int end) {
        vector<vector<int>>adj(V);
        vector<bool>visited(V,0);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
       return DFS(strt,strt,end,visited,adj);
    }
};