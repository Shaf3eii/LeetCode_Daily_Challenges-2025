class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = (int)grid.size(), cols = (int)grid[0].size();
        bool used[rows][cols]; // boolean matrix to track if the server used in a previous row
        memset(used, false, sizeof used);
        int connected = 0;
        // iterate over each row 
        for (int r = 0; r < rows; ++r) {
            int cnt = 0;
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    cnt += 1;
                    used[r][c] = true;
                }
            }
            // if the count of servers in a single row > 1 these will make a communicated server
            if (cnt > 1) connected += cnt;
            else { // otherwise, make the single server unused again
                for (int c = 0; c < cols; ++c) used[r][c] = false;
            }
        }
        // iterate over each column
        for (int c = 0; c < cols; ++c) {
            int cnt = 0, old = 0;
            for (int r = 0; r < rows; ++r) {
                if (grid[r][c] == 1) {
                    cnt += 1;
                    old += used[r][c]; // avoid count an used server
                }
            } // if the count of servers in a single column > 1, add the new communicated server
            if (cnt > 1) connected += cnt - old;
        }
        return connected;
    }
};