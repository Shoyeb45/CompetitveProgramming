#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int n;
vector<string> a;

void solve() {
    cin >> n;
    a.resize(n);
    loop(i, n) {
        cin >> a[i];
    }    

    map<string, int> mp;

    for(int i = n - 1; i >= 0; i--) {
        if(mp.find(a[i]) != mp.end()) {
            continue;
        } else {
            cout << a[i] << '\n';
            mp[a[i]] = 0;
        }
    }
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}