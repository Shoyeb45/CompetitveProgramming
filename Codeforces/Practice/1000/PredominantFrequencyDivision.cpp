#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
// #include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS                                                                                                            \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector pref(4, vector<int>(n, 0));
    for (int i = 1; i <= 3; i++) {
        pref[i][0] = a[0] == i;
    }

    for (int i = 1; i < n; i++) {
        pref[1][i] += pref[1][i - 1] + (a[i] == 1);
        pref[2][i] += pref[2][i - 1] + (a[i] == 2);
        pref[3][i] += pref[3][i - 1] + (a[i] == 3);
    }

    int mn = INT_MAX;

    if (pref[1][0] >= pref[2][0] + pref[3][0]) {
        mn = pref[1][0] + pref[2][0] - pref[3][0];
    }

    for (int i = 1; i < n - 1; i++) {
        if (pref[1][i] + pref[2][i] - pref[3][i] >= mn) {
            cout << "YES\n";
            return;
        }

        if (pref[1][i] >= pref[2][i] + pref[3][i]) {
            mn = min(pref[1][i] + pref[2][i] - pref[3][i], mn);
        }
        if (mn == INT_MAX)
            continue;
    }
    cout << "NO\n";
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