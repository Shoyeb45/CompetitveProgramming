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
    int n, m;
    string s;
    cin >> n >> m >> s;

    ll curr = 0, mn = 0;
    ll temp = n;


    while (m--) {
        int x;
        cin >> x;
        curr += x;
        temp += x;

        mn = min(mn, curr);
    }

    int k = temp - (n + mn);
    debug(k, n - mn);
    debug(mn);
    if (mn < 0 && abs(mn) >= n) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 0; i < n + mn; i++) {
        cout << s[i];
    }
    while (k--) cout << '0';
    cout << "\n";
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