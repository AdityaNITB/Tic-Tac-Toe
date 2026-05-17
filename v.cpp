#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
 int n; 
 cin >> n;
 int arr[n];
 for(int i=0; i<n; i++) {
   cin >> arr[i];
 }
 float sum=0;
 for(int i=0; i<n; i++) {
   sum+=arr[i];
 }
 float a=float(sum)/float(n);
 cout << a << endl;
   return 0;
}