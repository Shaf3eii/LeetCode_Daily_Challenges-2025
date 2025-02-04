class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int cur = nums[0], Max = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            cur = nums[i] > nums[i - 1] ? cur + nums[i] : nums[i];
            Max = max(cur, Max);
        } 
        return Max;
    }
};