class Solution {
    int sz; // the size of the graph
    vector<bool> vis;            // boolean vector to mark the visited nodes
    vector<bool> terminal;       // boolean vector to mark the terminal nodes
    vector<bool> unsafe;         // boolean vector to determine if the node is un safe (all its possible paths don't lead to terminal node)
    vector<vector<int>> adjList; // adjList to reprsent the graph
    bool dfs(int node) {
        if (terminal[node]) return true; // if we reach a terminal node, return true
        if (vis[node]) return false;     // if we have a cycle, return false
        vis[node] = true;                // mark current node as visited
        unsafe[node] = true;             // mark current node as unsafe (not terminal)
        for (auto neighbor : adjList[node]) { // iterate over all neighbors
            if (unsafe[neighbor] or !dfs(neighbor)) { // if the neighbor is not safe or returned false (cycle)
                unsafe[node] = false; // remove current node from the unsafe mode
                return false; // we can't reach terminal node
            }
        }
        unsafe[node] = false;  // mark the node as safe soFar
        terminal[node] = true; // the current node have reached the terminal
        return true; // if we reached a terminal node, return true
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        sz = (int)graph.size();
        adjList = graph;
        vis.resize(sz);
        terminal.resize(sz); 
        unsafe.resize(sz);
        for (int node = 0; node < sz; ++node) {
            if ((int)graph[node].size() == 0) { // if the node has no outgoing paths
                terminal[node] = true; // mark it as terminal node
            }
        }
        for (int node = 0; node < sz; ++node) { // dfs over all nodes
            dfs(node);
        }
        vector<int> safeNodes; // track the safe nodes as the answer
        for (int node = 0; node < sz; ++node) {
            if (terminal[node]) { // if the node is terminal, push it to the answer
                safeNodes.push_back(node);
            }
        }
        return safeNodes;
    }
};
