class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int cols = (int)grid[0].size();
        // calculate the prefix of the first row, and the suffix of the scond row
        vector<long long> pre(cols, 0), suf(cols , 0);
        pre[0] = grid[0][0];
        for (int c = 1; c < cols; ++c) {
            pre[c] = grid[0][c] + pre[c - 1];
        }
        suf[0] = grid[1][cols - 1];
        for (int c = cols - 2; c >= 0; --c) {
            suf[c] = grid[1][c] + suf[c + 1];
        }
        long long robot = LLONG_MAX;
        for (int c = 0; c < cols; ++c) {
            // iterate over each column and determine the max remainig value between prefix(first row) and suffix(second row)
            long long firstRow = pre[cols - 1] - pre[c];
            long long secondRow =  suf[c];
            robot = min(robot, max(firstRow, suf[0] - secondRow));
        }
        return robot;
    }
};




// another solution
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
