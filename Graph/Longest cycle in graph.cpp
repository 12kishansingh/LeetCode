class Solution {
public:
    int ans = -1;

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path, int cnt) {
        cnt++;
        visited[node] = 1;
        path[node] = cnt;

        for (int x : adj[node]) {
            if (!visited[x]) {
                dfs(x, adj, visited, path, cnt);
            } 
            else if (path[x]) { 
                int curr = path[node] - path[x] + 1;
                ans = max(ans, curr);
            }
        }

        path[node] = 0; 
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        vector<int> visited(n, 0), path(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, path, 0);
            }
        }

        return ans;
    }
};
