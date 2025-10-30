class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dest(n * n + 1, -1);
        int idx = 1;
        bool f = true;

        // Flatten the board
        for (int i = n - 1; i >= 0; i--) {
            if (f) {
                for (int j = 0; j < n; j++) {
                    dest[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    dest[idx++] = board[i][j];
                }
            }
            f = !f;
        }

        // Build adjacency list
        unordered_map<int, vector<int>> adj;
        for (int i = 1; i <= n * n - 1; i++) {
            for (int j = 1; j <= 6; j++) {
                int next = i + j;
                if (next <= n * n) {
                    if (dest[next] != -1)
                        adj[i].push_back(dest[next]);
                    else
                        adj[i].push_back(next);
                }
            }
        }

        // BFS for shortest path
        vector<int> visited(n * n + 1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        int cnt = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int p = q.front(); q.pop();
                if (p == n * n) return cnt;
                for (auto x : adj[p]) {
                    if (!visited[x]) {
                        visited[x] = 1;
                        q.push(x);
                    }
                }
            }
            cnt++;
        }

        return -1;
    }
};
