#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        if(c>b) {
            c=c%b;
            if(c>=a) {
                cout << 0 << endl;
            }
            else if(c<a) {
                cout << a-c << endl;
            }
        }
        else if(c==b) {
            if(a>=c) {
                cout << b << endl;
            }
            else { 
                cout << a << endl;
            }
        }
        else {
            if(c>=a) {
                cout << 0 << endl;
            }
            else if(c<a) {
                cout << a-c << endl;
            }
        }
    }
    return 0;
}
