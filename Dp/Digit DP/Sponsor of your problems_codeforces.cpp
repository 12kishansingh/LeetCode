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

int dp[11][2][2];
string r, l;
int recur(int idx, int tight, int tightr)
{
    if (idx == l.size())
        return 0;
    if (dp[idx][tight][tightr] != -1)
        return dp[idx][tight][tightr];
    int ans = INT_MAX;
    int low = (tight == 1) ? l[idx] - '0' : 0;
    int high = (tightr == 1) ? r[idx] - '0' : 9;
    for (int i = low; i <= high; i++)
    {
        int cost = 0;
        if (i == l[idx] - '0')
            cost++;
        if (i == r[idx] - '0')
            cost++;
        int curr = recur(idx + 1, (tight & (i == l[idx] - '0')), (tightr & (i == r[idx] - '0')));
        ans = min(ans, curr + cost);
    }
    return dp[idx][tight][tightr] = ans;
}
void solve()
{
    ll L, R;
    cin >> L >> R;
    r = to_string(R);
    l = to_string(L);
    memset(dp, -1, sizeof(dp));
    int ans = recur(0, 1, 1);
    cout << ans << endl;
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
