class Solution {
public:
    bool check(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            bool flag = true;
            for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
                if (nums[j] < nums[(j - 1 + n) % n]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};