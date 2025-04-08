#include <vector>
using namespace std;

class Solution {
public:
    vector<int> parent, rank;

    // Find operation with path compression
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    // Union operation with rank optimization
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;  // Fixed: Changed '==' to '='
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    // Detect cycle in an undirected graph
    bool detectCycle(int V, vector<int> adj[]) {
        parent.resize(V);
        rank.resize(V, 0);

        // Initialize parent of each node to itself
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                if (u < v) {  // To avoid processing the same edge twice
                    int parent_u = find(u);
                    int parent_v = find(v);

                    if (parent_u == parent_v) {
                        return true;  // Cycle detected
                    }
                    Union(u, v);
                }
            }
        }
        return false;  // No cycle detected
    }
};
