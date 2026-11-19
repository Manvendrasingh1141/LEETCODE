class Solution {
public:
    bool DFS(int node,vector<int>&visited,vector<vector<int>>& nums,stack<int>&st){
        visited[node] = 1;
        for(int j=0;j<nums[node].size();j++){
            int neighbour = nums[node][j];
            if(visited[neighbour]==1)return 0;

            if(!visited[neighbour]){
                if(!DFS(neighbour,visited,nums,st))return 0;
            }
        }
        visited[node]=2;
        st.push(node);
        return 1;
    }
    bool canFinish(int nc, vector<vector<int>>& nums) {
        
        vector<vector<int>>adj(nc);
        for(auto &x : nums){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
        }
        vector<int>visited(nc,0);
        stack<int>st;
        
        for(int i=0;i<nc;i++){
            if(!visited[i]){
                if(!DFS(i,visited,adj,st))return 0;
            }
        }
        return 1;
    }
};