class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq; //stops,node,cost(stops in current path)

        vector<int>dist(n,1e9);
        dist[src]=0;
        pq.push({0,{src,0}});
       
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops>k)continue; //continue on this path bcz cross the limit of stops

            for(int j=0;j<adj[node].size();j++){
                int neighbour = adj[node][j].first;
                int wt = adj[node][j].second;

                if(dist[neighbour]>cost+wt && stops<=k){ //node + wt
                    dist[neighbour]=cost+wt;
                    pq.push({stops+1,{neighbour,dist[neighbour]}});
                }            
            }
        }
            
        if(dist[dst]==1e9)return -1;
        return dist[dst];
        
    }
};