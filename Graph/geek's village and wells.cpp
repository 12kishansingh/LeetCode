class Solution {
public:
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &grid) {
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        // Push all wells as BFS sources
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'W') {
                    q.push({i, j});
                }
            }
        }

        int cnt = 1;

        // Multi-source BFS
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto &x : dir) {
                    int nr = r + x[0];
                    int nc = c + x[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                        (grid[nr][nc] == 'H' || grid[nr][nc] == '.')) {
                        
                        if (grid[nr][nc] == 'H') {
                            ans[nr][nc] = 2 * cnt;
                        }
                        grid[nr][nc] = 'X'; // mark visited
                        q.push({nr, nc});
                    }
                }
            }
            cnt++;
        }

        // Houses that never reached any well
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'H') ans[i][j] = -1;
            }
        }

        return ans;
    }
};
