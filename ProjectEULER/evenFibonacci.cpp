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

void solve() {
    ll tn = 1, tn_ = 2, sum = 0;
    while(tn < 4e6) {
        cout << tn << " ";
        if(tn % 2 == 0)
            sum += tn;
        ll temp = tn;
        tn = tn_;
        tn_ = temp + tn;
    }
    cout << '\n' << "Sum: " << sum;
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