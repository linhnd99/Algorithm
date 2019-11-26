#include <bits/stdc++.h>
#define lim 1000000000000000
using namespace std;

pair<long long,long long> a[1000001];
long long f[1000001],res[1000001],res2[1000001],trace[1000001];
int n;

int main()
{
    freopen("F.INP","r",stdin);
    freopen("F.OUT","w",stdout);
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
    f[3]=f[3-2]+a[3].first-a[3-2].first;
    f[4]=f[4-3]+a[4].first-a[4-3].first;
    f[5]=f[5-4]+a[5].first-a[5-4].first;
    trace[1]=trace[2]=0;
    trace[3]=0;
    trace[4]=0;
    trace[5]=0;
    for (int i=6;i<=n;i++)
    {
        if (i-3>=1)
        {
            //f[i]=min(f[i],f[i-3]+a[i].first-a[i-2].first);
            if (f[i]>f[i-3]+a[i].first-a[i-2].first)
            {
                f[i]=f[i-3]+a[i].first-a[i-2].first;
                trace[i]=i-3;
            }
        }
        if (i-4>=1)
        {
            //f[i]=min(f[i],f[i-4]+a[i].first-a[i-3].first);
            if (f[i]>f[i-4]+a[i].first-a[i-3].first)
            {
                f[i]=f[i-4]+a[i].first-a[i-3].first;
                trace[i]=i-4;
            }
        }
        if (i-5>=1)
        {
            //f[i]=min(f[i],f[i-5]+a[i].first-a[i-4].first);
            if (f[i]>f[i-5]+a[i].first-a[i-4].first)
            {
                f[i]=f[i-5]+a[i].first-a[i-4].first;
                trace[i]=i-5;
            }
        }
    }
    //for (int i=1;i<=n;i++) cout << a[i].first << " ";cout<<endl;
    //for (int i=1;i<=n;i++) cout << f[i] << " ";cout<<endl;
    int index = n;
    int gr=1;
    while (index>=1)
    {
        for (int i=index;i>trace[index];i--)
        {
            res[i]=gr;
        }
        gr++;
        index=trace[index];
    }
    for (int i=1;i<=n;i++)
        res2[a[i].second] = res[i];
    cout << f[n] << " " << gr-1<<endl;
    for (int i=1;i<=n;i++)
        cout << res2[i]<< " ";
    return 0;
}

