class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, bool> exist;
        int n = (int)nums.size();
        int ans = 0;
        for (int a = 0; a < n; ++a) {
            for (int b = n - 1; b > a; --b) {
                int prod = nums[a] * nums[b];
                unordered_map<int, bool> exist;
                for (int c = a + 1; c < b; ++c) {
                    if (prod % nums[c] == 0) {
                        ans += bool(exist.find(prod / nums[c]) != exist.end()) * 8;
                        exist[nums[c]] = true;
                    }
                }
            }
        }
        return ans;
    }
};