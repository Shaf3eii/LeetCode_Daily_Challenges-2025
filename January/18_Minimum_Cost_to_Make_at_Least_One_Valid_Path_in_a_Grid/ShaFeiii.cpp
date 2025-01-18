class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        int rows = (int)grid.size(), cols = (int)grid[0].size();
        auto isValid = [&](int r, int c) {
        return (r < rows and r >= 0 and c < cols and c >= 0);
        };
        vector<vector<int>> weighted(rows, vector<int> (cols, 10000));
    //    vector<vector<bool>> vis(102, vector<bool> (102, false));
        deque<pair<int, int>> dq;
        dq.emplace_back(0, 0);
        weighted[0][0] = 0;
        while (!dq.empty()) {
            auto cell = dq.front();
            dq.pop_front();
            int row = cell.first, col = cell.second;
            for (int d = 0; d < 4; ++d) {
                int nx = row + dx[d], ny = col + dy[d];
                int cost = (grid[row][col] != (d + 1) ? 1 : 0);
                if (isValid(nx, ny) and cost + weighted[row][col] < weighted[nx][ny]) {
                    weighted[nx][ny] = cost + weighted[row][col];
                    if (cost) dq.emplace_back(nx, ny);
                    else      dq.emplace_front(nx, ny);
                }
            }
        }
        return weighted[rows - 1][cols - 1];
    }
};