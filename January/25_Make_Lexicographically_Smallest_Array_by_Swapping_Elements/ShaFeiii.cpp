class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = (int)nums.size();
        vector<int> idx(n, 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){return nums[a] < nums[b];});
        vector<vector<int>> graph = {{idx[0]}};
        int prev = nums[idx[0]];
        for (int i = 1; i < n; ++i) {
            int pos = idx[i];
            int val = nums[pos];
            if (val - prev <= limit) graph.back().push_back(pos);
            else                     graph.push_back({pos});
            prev = val;
        }

        for (auto group : graph) {
            vector<int> vals;
            for (auto id : group) vals.push_back(nums[id]);
            sort(group.begin(), group.end());
            for (int i = 0; i < (int)group.size(); ++i) {
                nums[group[i]] = vals[i];
            }
        }
        return nums;
    }
};