#include <bits/stdc++.h>
#define int long long
using namespace std;
void f(int a,vector<int> &vec1) {
    int count=0;
    vec1.push_back(a);
    while(a>1) {
        if(a%2==0) {
        a=a/2;
        count++;
        }
        else {
            a=a+1;
            a=a/2;
            count+=2;
        }
        vec1.push_back(a);
    }
    return ;
}
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
        int arr1[n][100];
        for(int i=0; i<n; i++) {
            for(int j=0; j<100; j++) {
                arr1[i][j]=0;
            }
        }
        vector<int> vec1;
        for(int i=0; i<n; i++) {
            f(arr[i],vec1);
        }
    }
    return 0;
}