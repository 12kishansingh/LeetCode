#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(),order_of_key()
typedef long long ll;
#define all(x) begin(x), end(x)
const int M = 1e9 + 7;
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
        cout << it << " ";
    return ostream;
}

int dp[20][2][4];
int recur(string &s, int idx, int tight, int cnt)
{
    if (idx == s.size())
        return 1;

    if (dp[idx][tight][cnt] != -1)
        return dp[idx][tight][cnt];
        
    int limit = (tight == 1) ? s[idx] - '0' : 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        int cnt1 = cnt + ((i > 0) ? 1 : 0);
        if (cnt1 <= 3)
        {
            ans += recur(s, idx + 1, (tight & (i == s[idx] - '0')), cnt1);
        }
    }
    return dp[idx][tight][cnt] = ans;
}

void solve()
{
    ll L, R;
    cin >> L >> R;

    memset(dp, -1, sizeof(dp));
    string r = to_string(R);
    int right = recur(r, 0, 1, 0);

    int left = 0;
    if (L > 0)
    {
        memset(dp, -1, sizeof(dp));
        string l = to_string(L - 1);
        left = recur(l, 0, 1, 0);
    }
    else
    {
        left = 0;
    }

    cout << right - left << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
