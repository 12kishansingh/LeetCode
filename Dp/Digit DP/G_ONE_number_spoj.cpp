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

// cin >> vector<T>
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &it : v)
        is >> it;
    return is;
}

// cout << vector<T>
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &c)
{
    for (auto &it : c)
        os << it << " ";
    return os;
}

// dp[idx][tight][sum_of_digits]
long long dp[20][2][200];

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

long long recur(const string &s, int idx, int tight, int sum)
{
    if (idx == (int)s.size()) {
        return is_prime(sum) ? 1 : 0;
    }

    if (dp[idx][tight][sum] != -1) return dp[idx][tight][sum];

    int limit = (tight == 1) ? s[idx] - '0' : 9;
    long long ans = 0;
    for (int d = 0; d <= limit; ++d) {
        int sum1 = sum + (d > 0 ? d : 0);
        ans += recur(s, idx + 1, (tight && (d == (s[idx] - '0'))) ? 1 : 0, sum1);
    }

    return dp[idx][tight][sum] = ans;
}

void solve()
{
    ll L, R;
    cin >> L >> R;

    memset(dp, -1, sizeof(dp));
    string r = to_string(R);
    long long right = recur(r, 0, 1, 0);

    long long left = 0;
    if (L > 0) {
        memset(dp, -1, sizeof(dp));
        string l = to_string(L - 1);
        left = recur(l, 0, 1, 0);
    } else {
        left = 0;
    }

    cout << (right - left) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
