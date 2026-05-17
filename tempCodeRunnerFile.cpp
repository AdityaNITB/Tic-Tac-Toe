#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int t;
  cin >> t;
  for(int i=0; i<t; i++) {
    int x,y;
    cin >> x >> y;
    int a,b;
    cin >> a >> b;
    if(2*a<=b) {
     int adi=x+y;
     cout << adi*a << endl;
    }
    else {
      int p=min(x,y);
      int q=max(x,y);
      int sum=0;
      sum+=p*b+(q-p)*a;
      cout << sum << endl;
    }
  }
  return 0;
} 