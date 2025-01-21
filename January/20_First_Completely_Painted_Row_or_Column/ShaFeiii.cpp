class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int rows = (int)mat.size();
        const int cols = (int)mat[0].size();
        // track the number of painted rows and cols
        vector<int> paintedRows(rows, cols);
        vector<int> paintedCols(cols, rows);
        // save the arr values indices in the matrix
        map<int, pair<int, int>> valIndex;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                valIndex[mat[r][c]] = {r, c};
            }
        }
        for (int i = 0; i < (int)arr.size(); ++i) {
            // paint the row and col that the val exist in 
            const auto row = valIndex[arr[i]].first;
            const auto col = valIndex[arr[i]].second;
            paintedRows[row]--; 
            paintedCols[col]--;
            // if a row or a col have painted fully (it's size is 0) then we have reach
            if (!paintedRows[row] or !paintedCols[col]) return i;
        }
        return (int)arr.size() - 1;
    }
};
