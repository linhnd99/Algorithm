#include <bits/stdc++.h>

using namespace std;

int n;
long long res[1000001];
pair<long long, long long> a[1000001];

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a[i].first=x;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    int i=1;
    int team=1;
    long long s=0;
    while (i<=n)
    {
        for (int j=i;j<=min(n,i+2);j++)
            res[j]=team;
        s=s+a[min(n,i+2)].first-a[i].first;
        i=i+3;
        while (a[i-1].first==a[i].first && i<=n)
        {
            res[i]=team;
            i++;
        }
        team++;
    }
    for (int j=n-2;j<n;j++)
        if (res[j]!=res[j+1])
        {
            res[j+1]=res[j];
            s=s-a[i].first+a[i+1].first;
        }
    cout << team << " " <<s<<endl;
    for (int i=1;i<=n;i++)
        cout << res[a[i].second] << " ";
    return 0;
}
