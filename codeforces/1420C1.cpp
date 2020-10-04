#include <bits/stdc++.h>

using namespace std;

long long t,n,q,a[1000001];

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> q;
        for (int i=1;i<=n;i++)
            cin >> a[i];

//        f[0][0]=f[0][1]=0;
//        f[1][0]=a[1]; //+
//        f[1][1]=0; //-
        long long max0=a[1], max1=-2000000000;
        for (int i=2;i<=n;i++)
        {
            max0=max(max0,max(max1+a[i],a[i]));
            max1=max(max1,max0-a[i]);
        }
        cout << max(max0,max1) <<endl;
    }
    return 0;
}
