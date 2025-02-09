class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n = (int)nums.size();
            long long ans = 0;
            unordered_map<int, int> occ; // good pairs so Far
            for (int i = 0; i < n; ++i) {
                int cur = i - nums[i]; // current pair
                ans += i - occ[cur]; // ans += bad pairs so Far
                occ[cur]++; 
            }
            return ans;
        }
    };