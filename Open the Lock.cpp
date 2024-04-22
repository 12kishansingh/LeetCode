//BFS ---level template 
class Solution {
public:
void fill(queue<string>&q,string &curr,unordered_set<string>&s){
    for(int i=0;i<4;i++){
        char ch=curr[i];
        char dec=ch=='0'? '9': ch-1;
        char inc=ch=='9'? '0': ch+1;

        curr[i]=dec;
        if(s.find(curr)==s.end()){
            s.insert(curr);
            q.push(curr);
        }
        curr[i]=inc;
        if(s.find(curr)==s.end()){
            s.insert(curr);
            q.push(curr);
        }
        curr[i]=ch;

    }

}
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>s(deadends.begin(),deadends.end());
        string start="0000";
        if(s.find(start)!=s.end()){//starting one is in deadend
            return -1;
        }
        queue<string>q;
        q.push(start);
        int lvl=0;
        while(!q.empty()){
            int n=q.size();//elements in current level
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return lvl;
                }
                fill(q,curr,s);
            }
            lvl++;
        }
        return -1;
        
    }
};
