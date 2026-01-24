#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;


void solve() {
    int n;
    cin >> n;

    vector<int> c(n), v(n);

    for (int &x: c) cin >> x;
    for (int &x: v) cin >> x;

    map<int, ll> mp;


    ll C = 0, V = 0;
    for (int i = 0; i < n; i++) {
        mp[v[i]] += c[i];
        C += c[i];
        V += (ll) c[i] * v[i];
    }

    ll low = 1, high = C;
    ll ans = high;
    debug(C, V);

    vector<pair<ll, ll>> vp(range(mp));
    reverse(rrange(vp));

    auto check = [&](ll x) -> bool {
        ll curr = x, curr_val = 0;

        for (auto &[v_i, c_i]: vp) {
            if (curr == 0) break;
            if (curr <= c_i) {
                curr_val += curr * v_i;
                curr = 0;
            } else {
                curr -= c_i;
                curr_val += c_i * v_i;
            }
        }

        double t = (1 - (double) x / (double) C) * V;
        bool ans = curr_val >= t;
        debug(t, curr_val, x, ans);
        return ans;
    };

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}