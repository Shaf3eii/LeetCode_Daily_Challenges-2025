class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colors;  
        unordered_map<int, int> sizeSoFar;
        vector<int> ans;
        int n = (int)queries.size();
        for (int i = 0; i < n; ++i) {
            int label = queries[i][0];
            int color = queries[i][1];
            if (!colors[label]) {
                colors[label] = color;
                sizeSoFar[color]++;
            } else {
                int prevColor = colors[label];
                sizeSoFar[prevColor]--;
                if (sizeSoFar[prevColor] == 0) {
                  sizeSoFar.erase(prevColor);
                }
                colors[label] = color;
                sizeSoFar[color]++;
            }
            ans.push_back((int)sizeSoFar.size());
        }
        return ans;
    }
};