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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (auto &x: a) cin >> x;

    if (n == 2) {
        cout << min(a[0], a[1]) << "\n";
        return;
    }

    ll ans = 0;
    for (int i = 0; i < n - 2; i++) {
        vector<int> tmp = {a[i], a[i + 1], a[i + 2]};
        sort(range(tmp));

        ll smallest = tmp[0];
        ll middle = tmp[1];

        if (smallest + k > middle) {
            ans = max(ans, middle);
        } else {
            ans = max(ans, smallest + k);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        ans = max(ans,(ll) min(a[i], a[i + 1]));
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