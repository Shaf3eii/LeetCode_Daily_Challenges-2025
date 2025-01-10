#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = (int)nums.size();
        long long tot = 0, cur = 0;
        for (int i = 0; i < n; ++i)
            tot += nums[i];
        int splits = 0;
        for (int i = 0; i < n - 1; ++i) {
            tot -= nums[i];
            cur += nums[i];
            if (cur >= tot) splits++;
        }
        return splits;
    }
};

int main() {

    return 0;
}