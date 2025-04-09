class Solution {
public:
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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int comp=n;
        for(auto &v:connections){
            if(find(v[0])!=find(v[1])){
                comp--;
                Union(v[0],v[1]);
            }
        }
        return comp-1;
    }
};
