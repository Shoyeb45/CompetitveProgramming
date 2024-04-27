#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// Constructor is used to construct the object
class Rectangle {
public:
    int len;
    int bre;

    // Defualt constructor - no arguments passed
    Rectangle() {
        len = 12;
        bre = 34;
    }

    // Paramterised constructor
    Rectangle(int x, int y) {
        len = x;
        bre = y;
    }

    // Copy constructor - To replicate object
    Rectangle(Rectangle &r) {
        len = r.len;
        bre = r.bre;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Making object by defualt constructor
    Rectangle r1;
    cout << r1.len << " " << r1.bre << '\n';

    // Making object by parametised constructor
    Rectangle r2(4, 5);
    cout << r2.len << " " << r2.bre << '\n';
    
    // Making object by copy constructor
    Rectangle r3 = r2;
    cout << r3.len << " " << r3.bre << '\n';
    
    return 0;
}
