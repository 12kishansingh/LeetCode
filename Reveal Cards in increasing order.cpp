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
