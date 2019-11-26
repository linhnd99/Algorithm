#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long f[100001],a[100001],res[100001];

int main()
{
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            f[i]=0;
            res[i]=0;
        }
        f[1]=1;
        for (int i=2; i<=n; i++)
        {
            f[i]=1;
            for (int j=1;j<i;j++)
                if (a[j]<a[i]) f[i]=max(f[i],f[j]+1);
        }
        long long ma=0;
        for (int i=1;i<=n;i++)
        {
            ma=max(ma,f[i]);
        }

        for (int i=n;i>=1;i--)
        {
            if (f[i]==ma) res[f[i]]++;
            if (f[i]<ma)
                res[f[i]]=(res[f[i]] + res[f[i]+1]) % mod;
        }
        ma=0;
        cout << res[1]<<endl;
    }
    return 0;
}
