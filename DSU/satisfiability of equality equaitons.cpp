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
        return ;
    }
    if(rank[xparent]>rank[yparent]){
        parent[yparent]=xparent;
    }
    else if(rank[xparent]<rank[yparent]){
        parent[xparent]=yparent;
    }
    else{
        parent[xparent]=yparent;
        rank[yparent]++;
    }
}
    bool equationsPossible(vector<string>& e) {
       parent.resize(26);
       rank.resize(26,0);

       for(int i=0;i<26;i++){
        parent[i]=i;
       }

        for(string &s:e){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');// union of equal chars
            }

        }
        // != cases
        for(string &s:e){
            if(s[1]=='!'){
               char first=s[0];
               char sec=s[3];
               int pf=find(first-'a');
               int ps=find(sec-'a');
               if(pf==ps){
                return false;
               }

            }

        }
        return true;
    }
};
