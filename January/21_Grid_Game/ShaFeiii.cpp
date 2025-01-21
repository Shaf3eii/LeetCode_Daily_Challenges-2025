class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int cols = (int)grid[0].size(); // the number of columns in the grid
        // calculate the sum of the first row
        long long firstRowSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long secondRowSum = 0;
        long long robot = LLONG_MAX;
        for (int c = 0; c < cols; ++c) {
            // iterate over the first row and determine the max remainig value from the two paths
            firstRowSum -= grid[0][c];
            robot = min(robot, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][c];
        }
        return robot;
    }
};