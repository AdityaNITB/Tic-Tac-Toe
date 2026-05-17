#include <bits/stdc++.h>
using namespace std;
#define int long long
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
       for(int i=0; i<n; i++) {
        if(arr[i]%2==1) {
            vec1.push_back(arr[i]);
        }
        else {
            vec2.push_back(arr[i]);
        }
       }
       sort(vec1.begin(),vec1.end());
       sort(vec2.begin(), vec2.end());
       int i=vec1.size();
       int j=vec2.size();
       int count=0;
       vector<int> vec3;
       while(i>0 && j>0) {
        count+=vec1[i-1];
        count+=vec2[j-1];
        vec3.push_back(vec1[i-1]);
        vec3.push_back(vec2[j-1]);
        i--;
        j--;
       }
       if(i>0) {
        if(count%2==0) {
            count+=vec1[i];
            vec3.push_back(vec1[i]);
        }
       }
       if(j>0) {
        if(count%2==1) {
            count+=vec2[j];
            vec3.push_back(vec2[i]);
        }
       }
       for(int i=0; i<vec3.size(); i++) {
        cout << vec3[i] << " ";
       }
       cout << endl;
}
    return 0;
}
