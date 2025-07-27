class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);  // Path compression
    }

    void Union(int x, int y) {
        int xp = find(x);
        int yp = find(y);

        if (xp == yp) return;

        if (rank[xp] < rank[yp]) {
            parent[xp] = yp;
        } else if (rank[xp] > rank[yp]) {
            parent[yp] = xp;
        } else {
            parent[yp] = xp;
            rank[xp]++;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < edges.size(); i++) {
            Union(edges[i][0], edges[i][1]);
        }

        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(find(i));
        }

        return st.size();  // Number of connected components
    }
};
