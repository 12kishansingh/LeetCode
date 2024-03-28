class Solution {
public:
    typedef pair<char,int>  p;
    struct lamda{
        bool operator()(p &p1,p &p2){
            return p1.second<p2.second;//max heap
        }
    };
    string frequencySort(string s) {
        priority_queue<p,vector<p>,lamda> pq;//priority queue with comparator function
        unordered_map<char,int>mp;
        for(char &ch:s){
            mp[ch]++;
        }
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        string st="";
        while(!pq.empty()){
            p temp=pq.top();
            pq.pop();
            st+=string(temp.second,temp.first);
        }
        return st;

    }
};
