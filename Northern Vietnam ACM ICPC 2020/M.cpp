#include <bits/stdc++.h>

using namespace std;


long long f[100001],f2[100001],f1[100001],a[100001];
int n;

long long getSum(int dau, int i)
{
    return f1[i]-f1[dau-1] - (f2[i]-f2[dau-1])*(dau-1);
}

int solve(int index)
{
    if (index == 0) return 0;
    if (f[index]!=0) return f[index];

    long long tong1 = a[index];
    long long tong2 = getSum(index,n);
    long long tong3 = solve(index-1);
    f[index] = max({tong1,tong2,tong3});
    return f[index];
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[n-i+1];

    f1[0]=0;
    f2[0]=0;
    for (int i=1;i<=n;i++)
    {
        f1[i]=f1[i-1]+a[i]*i;
        f2[i]=f2[i-1]+a[i];
    }

    f[0]=0;
    long long dau=1;
    f[1]=a[1];

    solve(n);
    long long ma = f[1];
    for (int i=2;i<=n;i++)
        ma = max (ma,f[i]);

    f[0]=0;
    f[1]=a[1];
    for (int i=2;i<=n;i++)
    {
        //dau = bs(a[i],1,i);
        //long long tong1 = f1[i]-f1[dau-1] - (f2[i]-f2[dau-1])*(dau-1);
        long long tong1 = getSum(dau,i);
        //cout << dau << " " << i << " " <<tong1<<endl;
        long long tong2 = a[i];
        if (tong1 < tong2)
        {
            f[i]=tong2;
            dau = i;
        }
        else
        {
            f[i]=tong1;
        }
    }
    ma = max(f[1],ma);
    for (int i=2;i<=n;i++)
        ma = max (ma,f[i]);
    //for (int i=1;i<=n;i++) cout << f[i] << " ";cout <<endl;
    cout << ma;
    return 0;
}
