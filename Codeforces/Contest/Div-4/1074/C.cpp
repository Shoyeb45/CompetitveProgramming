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
    set<int> a;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a.insert(x);
    }


    int ans = 1;

    vector<int> tmp(range(a));
    n = tmp.size();
    int cnt = 1;

    debug(tmp);
    for (int i = 1; i < n; i++) {
        if (tmp[i] - 1 == tmp[i - 1]) {
            cnt++;
        } else {
            debug(cnt);
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    
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