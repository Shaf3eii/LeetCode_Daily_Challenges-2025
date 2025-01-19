class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // 4-Direction arrays
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        int rows = (int)heightMap.size(), cols = (int)heightMap[0].size();
        vector<vector<bool>> vis(rows, vector<bool> (cols)); 
        // check if the cell is on the boundary
        auto isBounded = [&](int r, int c) {
            return (r == 0 or r == rows - 1 or c == 0 or c == cols - 1);
        };
        // check if the cell is valid to move into
        auto isValid = [&](int r, int c) {
            return (r >= 0 and r < rows and c >= 0 and c < cols and !vis[r][c]);
        };
        // Min heap to fill the smallest heights cells first
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        // push all boundaries, as they can't trap anything
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (isBounded(r, c)){
                    pq.push({heightMap[r][c], {r, c}});
                    vis[r][c] = true;
                }
            }
        }
        int trapped = 0;
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int val = cell.first;
            int row = cell.second.first;
            int col = cell.second.second;
            for (int d = 0; d < 4; ++d) {
                int nx = row + dx[d];
                int ny = col + dy[d];
                if (isValid(nx, ny)) {
                    int nval = heightMap[nx][ny];
                    if (nval < val) { // if the new cell height is less than current height, then trap it 
                        trapped += (val - nval);
                    }
                    pq.push({max(nval, val), {nx, ny}});
                    vis[nx][ny] = true;
                }
            }
        }
        return trapped;
    }
};