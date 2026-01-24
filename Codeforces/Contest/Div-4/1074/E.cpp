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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    set<int> r;

    auto find_pairs = [&](int x) -> pair<int, int> {
        if (r.empty()) return {-1, -1};

        pair<int, int> ans = {-1, -1};
        auto it = r.lower_bound(x);

        if (it != r.end()) {
            ans.second = *it;
        }

        if (it != r.begin()) {
            auto prev_it = it;
            prev_it--;
            ans.first = *prev_it;
        }

        return ans;
    };

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r.insert(a[i]);
    }

    map<int, vector<pair<int, int>>> mp;

    for (int i = 0; i < m; i++) {
        cin >> b[i];
        auto x = find_pairs(b[i]);
        if (x.first != -1) {
            mp[b[i] - x.first].push_back(make_pair(b[i], x.first));
        }
        if (x.second != -1) {
            mp[b[i] - x.second].push_back(make_pair(b[i], x.second));
        }
    }

    string s;
    cin >> s;

    int net_mov = 0;
    
    int alive = n;

    for (auto ch: s) {
        net_mov += ch == 'L' ? -1: 1;

        if (mp.find(net_mov) != mp.end() && mp[net_mov].size() > 0) {
            alive -= mp[net_mov].size();
            cout << max(0, alive) << " ";
            for (auto& [si, ri]: mp[net_mov]) {
                if (r.find(ri) != r.end()) r.erase(ri);
                auto p = find_pairs(si);
                if (p.first != -1) {
                    mp[si - p.first].push_back(make_pair(si, p.first));
                }
                if (p.second != -1) {
                    mp[si - p.second].push_back(make_pair(si, p.second));
                }
            }
            mp.erase(net_mov);
        } else {
            cout << max(0, alive) << " ";
        }
    }
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