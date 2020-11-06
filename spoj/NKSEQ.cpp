#include <bits/stdc++.h>

using namespace std;

long long a[100001],f[100002],n;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    long long s=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        s+=a[i];
        if (i==1) f[1]=a[1];
        else f[1]=min(f[1],s);
    }
    if (s<=0)
    {
        cout << 0<<endl;
        return 0;
    }

    f[n+1]=f[1];
    for (int i=n;i>=2;i--)
    {
        f[i]=min(a[i],a[i]+f[i+1]);
    }
    int res = 0;
    for (int i=1;i<=n;i++)
        if (f[i]>0) res++;
    cout << res;
    return 0;
}
