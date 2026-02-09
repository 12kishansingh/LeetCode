class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(prices[i]);
            int j=i+1;
            while( j<n&& prices[j]>st.top()){
                j++;
            }
           if(j<n) st.push(prices[j]);
            if(st.size()>1)ans[i]=(prices[i]-st.top());
            else ans[i]=st.top();
            st = stack<int>();
        }
        return ans;
    }
};
