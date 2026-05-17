#include <bits/stdc++.h>
using namespace std;
int main()
{   int t,n,a,b;
    cin >> t;
    while (t--)
    {   cin >> n >> a >> b;
        vector <int> v(n),z,w;
        for (int i=0;i<n;i++)
        {   cin >> v[i];
        }
        for (int i=0;i<n;i++)
        {   if (i<a||i>=b)
            {   w.push_back(v[i]);
            }
            else
            {   z.push_back(v[i]);
            }
        }
        int miind=min_element(z.begin(),z.end())-z.begin();
        int val=z[miind];
        int i=0;
        while (i<w.size()&&w[i]<val)
        {   cout << w[i] << " ";
            i++;
        }
        for (int j=miind;j<z.size();j++)
        {   cout << z[j] << " ";
        }
        for (int j=0;j<miind;j++)
        {   cout << z[j] << " ";
        }
        while (i<w.size())
        {   cout << w[i] << " ";
            i++;
        }
        cout << endl;
    }
    return 0;
}