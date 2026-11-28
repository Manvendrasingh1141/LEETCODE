
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long,int>, 
        vector<pair<long long,int>>,
        greater<pair<long long,int>>>q;

        q.push({0,0});
        dist[0] = 0;
        ways[0] = 1;

        while (!q.empty()) {
            long long current_time = q.top().first;
            int node = q.top().second;
            q.pop();

            if (current_time > dist[node])
                continue;

            for (int j=0;j<adj[node].size();j++) {

                int neighbour = adj[node][j].first;
                int tym = adj[node][j].second;
                long long new_time = current_time + tym;

                //this is the 1st tym i m coming with short distance
                if (dist[neighbour]>new_time) {
                    dist[neighbour]=new_time;
                    ways[neighbour]=ways[node];
                    q.push({new_time, neighbour});
                } else if (dist[neighbour]==new_time) {
                    ways[neighbour] =(ways[neighbour]+ways[node])%MOD;
                }
            }
        }

        return ways[n-1];
    }
};
