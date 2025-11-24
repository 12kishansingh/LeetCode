#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//find_by_order(),order_of_key()
typedef long long ll;
#define all(x) begin(x), end(x)
const int M=1e9+7;
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
for (auto &it : v)
cin >> it;
return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
for (auto &it : c)
cout << it <<" ";
return ostream;
}

int dp[12][12];// index,previous
int solve(vector<int>&a,int idx,int prev,int n){

    if(idx==n)return 1;
    if(dp[idx][prev]!=-1)return dp[idx][prev];
    int ans=0;
    for(int i=0;i<a.size();i++){
        if(prev==0|| abs(a[i]-prev)<=2){
            ans+=solve(a,idx+1,a[i],n); 
        }
    }
    return dp[idx][prev]=ans;

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t;
cin>>t;

for(int i=1;i<=t;i++){
    int m,n;cin>>m>>n;
    vector<int>a(m);
    cin>>a;
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<i<<": "<<solve(a,0,0,n)<<endl;
}
return 0;
}
