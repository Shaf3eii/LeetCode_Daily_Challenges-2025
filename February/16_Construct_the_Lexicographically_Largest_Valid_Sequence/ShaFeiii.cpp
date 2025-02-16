class Solution {
    public:
        vector<int> constructDistancedSequence(int n) {
            vector<int> ans(n * 2 - 1, -1);
            bitset<21> vis;
    
            function<bool(int)> solve = [&](int idx) {
                if (idx == (int)ans.size()){
                    return true;
                }
                if (~ans[idx]) {
                    return solve(idx + 1);  
                }
                for (int i = n; i > 0; --i) {
                    if (!vis[i]) {
                        int next = i == 1 ? idx : idx + i;
                        if (next < n * 2 - 1 and ans[idx] == -1 and ans[next] == -1){
                            ans[idx] = ans[next] = i;
                            vis[i] = true;
                            if (solve(idx + 1)) return true;
                            ans[idx] = ans[next] = -1;
                            vis[i] = false;
                        }
                    }
                }
                return false;
            };
            solve(0);
            return ans;
        }
    };