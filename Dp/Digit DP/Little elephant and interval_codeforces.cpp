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

// dp: pos, tight, first
long long dp[20][2][11];

long long recur(string &s, int idx, int tight, int first)
{
    int n = s.size();
    if (idx == n)
    {
        return (first != -1) ? 1 : 0;
    }
    int fi = (first == -1 ? 10 : first);
    if (dp[idx][tight][fi] != -1)
        return dp[idx][tight][fi];

    long long ans = 0;
    int limit = (tight == 1) ? (s[idx] - '0') : 9;

    for (int d = 0; d <= limit; ++d)
    {
        int ntight = (tight == 1 && d == limit) ? 1 : 0;

        if (idx == n - 1)
        {
            if (first == -1)
            {
                if (d == 0)
                    continue; // all zeros

                ans += recur(s, idx + 1, (tight & (d == s[idx] - '0')), d);
            }
            else
            {
                if (d != first)
                    continue;
                ans += recur(s, idx + 1, (tight & (d == s[idx] - '0')), first);
            }
        }
        else
        {
            int nfirst = first;
            if (first == -1)
            {
                if (d != 0)
                    nfirst = d;
                else
                    nfirst = -1;
            }
            ans += recur(s, idx + 1, (tight & (d == s[idx] - '0')), nfirst);
        }
    }

    dp[idx][tight][fi] = ans;
    return ans;
}

void solve()
{
    ll L, R;
    cin >> L >> R;
    string r = to_string(R);
    memset(dp, -1, sizeof(dp));
    long long right = recur(r, 0, 1, -1);

    ll Lminus = L - 1;
    if (Lminus < 0)
        Lminus = 0;
    string l = to_string(Lminus);
    memset(dp, -1, sizeof(dp));
    long long left = recur(l, 0, 1, -1);

    cout << (right - left) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
