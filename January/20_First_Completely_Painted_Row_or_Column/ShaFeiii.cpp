class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int rows = (int)mat.size();
        const int cols = (int)mat[0].size();
        vector<int> paintedRows(rows, cols);
        vector<int> paintedCols(cols, rows);
        map<int, pair<int, int>> valIndex;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                valIndex[mat[r][c]] = {r, c};
            }
        }
        for (int i = 0; i < (int)arr.size(); ++i) {
            const auto row = valIndex[arr[i]].first;
            const auto col = valIndex[arr[i]].second;
            paintedRows[row]--;
            paintedCols[col]--;
            if (!paintedRows[row] or !paintedCols[col]) return i;
        }
        return (int)arr.size() - 1;
    }
};