class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

        // Determine search space
        for (auto &s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)(s[1] + s[2]));
        }

        // Binary search
        for (int iter = 0; iter < 100; iter++) {
            double mid = (low + high) / 2.0;
            double above = 0.0, below = 0.0;

            for (auto &s : squares) {
                double y = s[1];
                double l = s[2];
                double top = y + l;

                if (top <= mid) {
                    below += l * l;
                } 
                else if (y >= mid) {
                    above += l * l;
                } 
                else {
                    below += l * (mid - y);
                    above += l * (top - mid);
                }
            }

            if (above > below)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
