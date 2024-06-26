#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n ;

        vector<int> a(n);

        loop(i, n)  cin >> a[i];
        
        int ans = -1000000007;
        for(int i = 0; i < n; i++)
            ans = max(ans, a[(i - 1 + n) % n] - a[i]);
        
        for(int i = 1; i < n; i++) 
            ans = max(ans, a[i] - a[0]);
            
        for(int i = 0; i < n - 1; i++) 
            ans = max(ans, a[n - 1] - a[i]);
    

        cout << ans << "\n";
    }
        return 0;
}