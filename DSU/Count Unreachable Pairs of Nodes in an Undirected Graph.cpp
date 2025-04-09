class Solution {
public:
// dsu
//union+find 
vector<int>parent,rank;
int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int xparent=find(x);
    int yparent=find(y);

    if(xparent==yparent){
        return;
    }
    if(rank[xparent]>rank[yparent]){
        parent[yparent]=xparent;
    }
    else if(rank[xparent]<rank[yparent]){
        parent[xparent]=yparent;
    }
    else {
        parent[xparent]=yparent;
        rank[yparent]++;
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;

        int cmp=n;
    
        for(auto &V:edges){
            int u=V[0];
            int v=V[1];
            Union(u,v); 
        }
        unordered_map<int,int>m;

        for(int i=0;i<n;i++){
            int papa=find(i);
            m[papa]++;
        }
        long long rem=n,ans=0;
        for(auto &it:m){
            long long curr=it.second;
            ans+=(curr)*(rem-curr);
            rem-=curr;
        }
        return ans;

    }
};
