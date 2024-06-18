// use of two pointers, filling the array using moduloe operator 
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        bool skip=false;
        vector<int>ans(n,0);
        sort(deck.begin(),deck.end());
        int j=0;
        for(int i=0;i<n;){
            if( ans[j]==0){
                if(skip==false){
                ans[j]=deck[i];
                i++;
                }
                skip=!skip;
            }
                j=(j+1)%n;
        }return ans;
        
    }
};
// use of queue simply
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        queue<int>q;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            q.push(i);
        }
        for(int i=0;i<n;i++){
            int idx=q.front();
            ans[idx]=deck[i];
            q.pop();
            if(!q.empty()){
            q.push(q.front());
            q.pop();
            }
        }return ans;
    }
};
