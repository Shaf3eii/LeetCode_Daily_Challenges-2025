class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int rows = (int)grid.size(), cols = (int)grid[0].size();
        vector<int> islands(250005, 0);

        function<bool(int, int)> valid = [&](int r, int c) {
            return r >= 0 and r < rows and c >= 0 and c < cols;
        };

        // DFS function to explore the island and mark it with a unique color
        // The color parameter is used to distinguish different islands
        function<int(int ,int, int)> dfs = [&](int r, int c, int color) {
            grid[r][c] = color;  // Mark the current cell with the current island's color
            int sz = 1;  // Initialize size of the island to 1 (the current cell)
            
            for (int d = 0; d < 4; ++d) {
                int nr = r + dx[d];  
                int nc = c + dy[d];  
                // If the new cell is within bounds and is land (1), explore it recursively
                if (valid(nr, nc) and grid[nr][nc] == 1) {
                    sz += dfs(nr, nc, color);  // Add the size of the neighboring island
                }
            }
            return sz;  // Return the size of the island found
        };

        // Variable to assign unique colors to different islands
        int color = 2;  // Start with color 2 (since 0 and 1 are already used in the grid)

        // First pass: DFS to find all islands and assign them unique colors
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If the cell contains land (1), perform DFS to explore the island
                if (grid[r][c] == 1) {
                    islands[color++] = dfs(r, c, color);  // Store the size of the island
                }
            }
        }

        int ans = *max_element(islands.begin(), islands.end());

        // Second pass: Try flipping each 0 to 1 and check the size of the largest island
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Only consider flipping 0's (water cells)
                if (grid[r][c] == 0) {
                    unordered_set<int> dif;  // To store the unique island colors around this cell
                    // Explore the four possible directions around the current water cell
                    for (int d = 0; d < 4; ++d) {
                        int nx = r + dx[d];  
                        int ny = c + dy[d]; 
                        // If the neighboring cell is within bounds and is part of an island
                        if (valid(nx, ny) and grid[nx][ny] > 1) {
                            dif.insert(grid[nx][ny]);  // Add the island color to the set
                        }
                    }
                    // Calculate the potential size of the island if the current cell is flipped to land
                    int cur = 1;  // Start with 1 (the flipped cell itself)
                    for (auto i : dif) cur += islands[i];  // Add the sizes of the neighboring islands
                    ans = max(ans, cur);  // Update the answer with the largest possible island size
                }
            }
        }

        return ans; 
    }
};
