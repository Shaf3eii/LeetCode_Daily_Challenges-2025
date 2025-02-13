#define ll             long long

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<>> pq;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            pq.push(nums[i]);
        }
        if (pq.top() >= k) return 0; // base case
        ll ans = 0;
        while (true) {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            ll val = x * 2 + y;
            pq.push(val);
            ans++;
            if (pq.top() >= k) break;
        }
        return ans;
    }
};