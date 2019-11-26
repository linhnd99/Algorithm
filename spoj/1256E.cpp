#include <bits/stdc++.h>
#define lim 1000000000000000
using namespace std;

pair<long long,long long> a[1000001];
long long f[1000001];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
    {
        long long x;
        cin >> x;
        a[i]=make_pair(x,i);
        f[i]=lim;
    }
    sort(a+1,a+1+n);
    f[1]=f[2]=0;
    for (int i=3;i<=n;i++)
    {
        if (i-2>=1)
        {
            f[i]=min(f[i],f[i-2]+a[i].first-a[i-2].first);
        }
        if (i-3>=1)
        {
            f[i]=min(f[i],f[i-3]+a[i].first-a[i-3].first);
        }
        if (i-4>=1)
        {
            f[i]=min(f[i],f[i-4]+a[i].first-a[i-4].first);
        }
    }
    cout << f[n]<<endl;
    return 0;
}
