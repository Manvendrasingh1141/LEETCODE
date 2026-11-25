class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e8));

        dist[0][0] = 0;
        set<pair<int, pair<int, int>>> s;
        s.insert({0, {0, 0}});

        vector<int> nx = {-1, 1, 0, 0};
        vector<int> ny = {0, 0, -1, 1};

        while (!s.empty()) {
            auto pr = *(s.begin());
            s.erase(s.begin());
            int i = pr.second.first;
            int j = pr.second.second;

            int currWt = pr.first;

            for (int dir = 0; dir < 4; dir++) {
                int dx = i + nx[dir];
                int dy = j + ny[dir];

                if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
                    if (max(abs(heights[dx][dy] - heights[i][j]), dist[i][j]) <
                        dist[dx][dy]) {
                        if (s.find({dist[dx][dy], {dx, dy}}) != s.end())
                            s.erase({dist[dx][dy], {dx, dy}});
                        dist[dx][dy] = max(abs(heights[dx][dy] - heights[i][j]),
                                           dist[i][j]);
                        s.insert({dist[dx][dy], {dx, dy}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};