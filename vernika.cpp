#include<bits/stdc++.h> 
using namespace std;
#define int long long
signed main() {
  int n,m;
  cin >> n >> m;
  int arr[n];
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }
  for(int i=0; i<n; i++) {
    if(arr[i]%m==0) {
      arr[i]-=1;
    }
  }
  int maxm=0;
  int pos=0;
  for(int i=0; i<n; i++) {
    if(arr[i]>=maxm) {
      maxm=arr[i];
      pos=i+1;
    }
  }
  if(m==1) {
    cout << pos << endl;
  }
  else {
  int x=maxm/m;
  int ans;
  int y=x*m;
  if(x==0) {
    cout << n << endl;
  }
 else  {
    for(int i=0; i<n; i++) {
      if((arr[i]%y)>0 && (arr[i]/y>0)) {
        ans=i;
      }
    }
    cout << ans+1 << endl;
  }
}
  return 0;
}