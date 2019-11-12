class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        if (grid.empty() || grid[0].empty()) return res;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int tmp = helper(grid, i, j);
                res = max(tmp, res);
            }
        }
        return res;
    }
    int helper(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 0;
        }
        if (grid[i][j] == 0) {
            return 0;
        }
        int count = 1;
        grid[i][j] = 0;
        count += helper(grid, i + 1, j);
        count += helper(grid, i - 1, j);
        count += helper(grid, i, j + 1);
        count += helper(grid, i, j - 1);
        return count;
    }
};
