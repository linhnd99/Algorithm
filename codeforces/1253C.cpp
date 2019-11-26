#include <bits/stdc++.h>

using namespace std;

long long n,k;
long long a[2000001],s[2000001],f[2000001];

int main()
{
    //freopen("F.INP","r",stdin);
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    //for (int i=1;i<=n;i++) cout << a[i]<< " ";cout<<endl;
    f[0]=0;
    s[0]=0;
    for (int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for (int i=1;i<=k;i++)
        f[i]=f[i-1]+a[i];
    for (int i=k+1;i<=n;i++)
        f[i]=f[i-k]+s[i];
    for (int i=1;i<=n;i++)
        cout << f[i]<< " ";
    return 0;
}
