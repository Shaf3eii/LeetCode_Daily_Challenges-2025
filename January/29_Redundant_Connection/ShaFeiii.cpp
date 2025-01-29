class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        function<bool(int, int, vector<bool>&)> dfs = [&](int u, int v, vector<bool>& vis) {
            vis[u] = true;
            for (auto n : adj[u]) {
                if (n == v) continue;
                if (vis[n] or dfs(n, u, vis)) return true;
            }
            return false;
        };


        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<bool> vis(edges.size() + 1, false);
            if (dfs(u, -1, vis)) return edge;
        }
        return {-1, -1};
    }
};