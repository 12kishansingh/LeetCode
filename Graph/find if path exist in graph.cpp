class Solution {
public:
bool solve(unordered_map<int,vector<int>>&adj,int s,int d,vector<bool>&visited){
if(s==d)return true;
if(visited[s]==true)return false;
visited[s]=true;

for(auto &it:adj[s]){
    if(solve(adj,it,d,visited)==true)return true;
}
return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int des) {
        unordered_map<int,vector<int>>adj;//adjecency list for graph
        for(vector<int>&edge:edges){
            int u=edge[0];
            int v=edge[1];
            //bidirectional graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        return solve(adj,source,des,visited);
    }
};
