#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
      cin >> arr[i];
    }
    vector<int> vec1;
    vector<int> vec2;
    int sum=0;
    for(int i=0; i<n; i++) {
      sum+=arr[i];
      vec1.push_back(sum);
    }
    if(sum%3!=0) {
      cout << 0 << " " << 0 << endl;
    }
    else {
      int p=arr[n-1]%3;
      for(int i=0; i<vec1.size(); i++) {
        if(vec1[i]%3!=p) {
          cout << i+1 << " ";
          break;
        }
      }
      cout << n-1 << endl;
    }
  }
  return 0;
}
