class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // 4-Directions
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        int rows = (int)isWater.size();
        int cols = (int)isWater[0].size();
        auto isValid = [&](int r, int c) { // function to check if the cell is Valid to move into
            return (r >= 0 and c >= 0 and r < rows and c < cols);
        };
        vector<vector<int>> newCells(rows, vector<int> (cols, -1)); // the result grid
        queue<pair<int, int>> q; // queue for BFS
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (isWater[r][c]) { // if the cell is water (cell == 1) push it into the queue
                    q.emplace(r, c);
                    newCells[r][c] = 0;
                } 
            }
        }
       int lvl = 1; // the height of the next layer
        for (int sz = (int)q.size(); sz; sz = (int)q.size()) {
            while (sz--) {
                auto cell = q.front();
                q.pop();
                int r = cell.first, c = cell.second;
                for (int d = 0; d < 4; ++d) {
                    int nx = r + dx[d];
                    int ny = c + dy[d];
                    if (isValid(nx, ny) and newCells[nx][ny] == -1) { // if the cell is valid and not visited 
                        newCells[nx][ny] = lvl; // change  the value of the cell to the current height
                        q.emplace(nx, ny);
                    }
                }
            }
            lvl++;
        }
        return newCells;
    }
};