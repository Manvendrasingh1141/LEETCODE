class Solution {
public:
    bool check(int row, int n, vector<string>& temp, int col) {
        int i = row, j = col;

        // Upper-left diagonal
        while (i >= 0 && j >= 0) {
            if (temp[i][j] == 'Q') return false;
            i--;
            j--;
        }

        // Upper-right diagonal
        i = row;
        j = col;
        while (i >= 0 && j < n) {
            if (temp[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(int row, int n, vector<bool>& col,
               vector<string>& temp, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!col[j] && check(row, n, temp, j)) {
                col[j] = true;
                temp[row][j] = 'Q';

                solve(row + 1, n, col, temp, ans);

                temp[row][j] = '.';
                col[j] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<vector<string>> ans;

        solve(0, n, col, temp, ans);

        return ans;
    }
};