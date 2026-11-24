class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        int dr[] = {-1, 1, 0, 0, -1, 1, -1, 1};
        int dc[] = {0, 0, -1, 1, -1, 1, 1, -1};
        priority_queue<array<int, 3>, vector<array<int, 3>>,
                       greater<array<int, 3>>>
            pq;

        dist[0][0] = 1;
        pq.push({1, 0, 0});

        while (!pq.empty()) {
            auto [steps, row, col] = pq.top();
            pq.pop();

            if (steps > dist[row][col])
                continue;
            if (row == n - 1 && col == n - 1)
                return steps;

            for (int i = 0; i < 8; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n ||
                    grid[newRow][newCol] == 1)
                    continue;

                if (steps + 1 < dist[newRow][newCol]) {
                    dist[newRow][newCol] = steps + 1;
                    pq.push({steps + 1, newRow, newCol});
                }
            }
        }

        return -1;
    }
};
