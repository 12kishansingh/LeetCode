class Solution {
public:
void dfs(int i,vector<int>&visited,vector<vector<int>>&adj){
    visited[i]=1;
    for(auto x:adj[i]){
        if(!visited[x]){
            dfs(x,visited,adj);
        }
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){return -1;}
        vector<vector<int>>adj(n);
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>visited(n);
        int components=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                components++;
            }
        }
        return components-1;
    }
};
