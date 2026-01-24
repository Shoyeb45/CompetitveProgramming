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
    set<int> a;
    for (int i = 0, x; i < 6; i++) {
        cin >> x;
        a.insert(x);
    }

    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &x: b) {
        cin >> x;
    }
    sort(range(b));


    int mn = b[0] - *a.begin();
    int mx = b[n - 1] - *a.rbegin();
    
    cout << mx - mn << "\n";
}   



int main() {
    NFS
    // #ifndef ONLINE_JUDGE
    //     freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
    //     freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
    //     freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    // #endif
    // int tt;
    // tt = 1;
    // cin >> tt;

    // for (int i = 1; i <= tt; i++) {
        solve();
    // }

    return 0;
}