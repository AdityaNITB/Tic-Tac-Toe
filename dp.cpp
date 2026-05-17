#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            arr[i]=i+1;
        }

    //     vector<int> ans(n);
    //     int p = n - 1;
    //     int i = 0, j = n - 1;

    //     while (i < j) {
    //         ans[p--] = a[j--];
    //         ans[p--] = a[i++];
    //     }

    //     if (i == j) {
    //         ans[p] = a[i];
    //     }

    //     for (int k = 0; k < n; k++) {
    //         cout << ans[k] << " ";
    //     }
    //     cout << "\n";
    // }
    vector<int> vec1(n);
    int p=n-1;
    int i=0;
    int j=n-1;
    while(i<j) {
        vec1[p--]=arr[j--];
        vec1[p--]=arr[i++];
    }
    if(i==j) {
        vec1[p]=arr[i];
    }
    for(int x=0; x<n; x++) {
        cout << vec1[x] << " ";
    }
    cout << endl;
    }
    return 0;
}