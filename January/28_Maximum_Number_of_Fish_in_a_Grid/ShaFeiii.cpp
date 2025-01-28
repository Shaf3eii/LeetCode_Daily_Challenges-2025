class Solution {
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = (int)grid.size(), cols = (int)grid[0].size();
        int fish = 0;
        function<bool(int, int)> valid = [&](int r, int c) {
            return (r >= 0 and r < rows and c >= 0 and c < cols and grid[r][c] > 0);
        };
        function<int(int, int)> dfs = [&](int r, int c) {
            int cur = grid[r][c];
            grid[r][c] = 0;
            for (int d = 0; d < 4; ++d) {
                int nx = dx[d] + r;
                int ny = dy[d] + c;
                if (valid(nx, ny)) {
                    cur += dfs(nx, ny);
                }
            }
            return cur;
        };
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] > 0) {
                    fish = max(fish, dfs(r, c));
                }
            }
        } 
        return fish;
    }
};