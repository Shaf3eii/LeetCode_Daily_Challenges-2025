class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            unordered_map<int, int> exist;
            int n = (int)nums.size();
            int ans = -1;
    
            function<int(int)> sumOfDigits = [&](int x) {
                int sum = 0;
                while (x > 0) {
                    sum += x % 10;
                    x /= 10;
                }
                return sum;
            };
    
            for (int i = 0; i < n; ++i) {
                int digitsSum = sumOfDigits(nums[i]);
                if (exist.find(digitsSum) != exist.end()) {
                    ans = max(ans, nums[i] + nums[exist[digitsSum]]);
                    exist[digitsSum] = nums[i] > nums[exist[digitsSum]] ? i : exist[digitsSum];
                } else {
                    exist[digitsSum] = i;
                }
            }
            return ans;
        }
    };