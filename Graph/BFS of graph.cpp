// GFG
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void bfs(vector<vector<int>>& adj, int i, vector<int>& ans, vector<bool>& visited) {
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
            // Process all neighbors of the current node
            for (auto x : adj[curr]) {
                if (!visited[x]) {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }

    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(), false);
        vector<int> ans;
        bfs(adj, 0, ans, visited);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
