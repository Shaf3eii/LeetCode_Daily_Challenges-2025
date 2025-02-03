class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        int cur = 1, Max = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                cur = 1;
            }
            Max = max(Max, cur);
        }
        cur = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                cur++;
            } else {
                cur = 1;
            }
            Max = max(Max, cur);
        }
        return Max;
    }
};


// Another Solution
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> inc(n + 1), dec(n + 1);
        inc[0] = dec[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) inc[i] = inc[i - 1] + 1;
            else                       inc[i] = 1;
            if (nums[i] < nums[i - 1]) dec[i] = dec[i - 1] + 1;
            else                       dec[i] = 1;
        } 
        return max(*max_element(inc.begin(), inc.end()), *max_element(dec.begin(), dec.end()));
    }
};