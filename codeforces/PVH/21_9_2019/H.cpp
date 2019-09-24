#include <bits/stdc++.h>

using namespace std;

long long a[100001];
int n;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    long long ma=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        ma = max(a[i],ma);
    }
    long long x=ma,s=0;
    for (int i=1;i<=n;i++)
    {
        s+=x-a[i];
    }
    while(true)
    {
        if (s>=ma) break;
        s+=n;
        ma++;
    }
    cout << ma;
    return 0;
}
