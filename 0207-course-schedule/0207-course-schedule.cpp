class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& nums) {
        
        vector<vector<int>>adj(nc);
        for(auto &x : nums){
            int u = x[1];
            int v = x[0];
            adj[u].push_back(v);
        }
        vector<int>inDeg(nc,0);
        vector<int>ans;
        queue<int>q;
        
        for(int i=0;i<nc;i++)
        for(int j=0;j<adj[i].size();j++){
        int neighbour = adj[i][j];
        inDeg[neighbour]++;
        }
        
        for(int i=0;i<nc;i++)
        if(inDeg[i]==0)q.push(i);

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(int j=0;j<adj[node].size();j++){
                int neighbour = adj[node][j];
                inDeg[neighbour]--;
                if(inDeg[neighbour]==0)q.push(neighbour);
            }
        }

        if(ans.size()==nc)return 1;
        return 0;
    }
};