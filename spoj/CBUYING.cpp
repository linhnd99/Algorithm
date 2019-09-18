#include <bits/stdc++.h>

using namespace std;

long long n,b;
pair<long long, long long> a[100001];

int main()
{
    //freopen("f.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> b;
    for (int i=1;i<=n;i++)
        cin >> a[i].first >> a[i].second;
    sort(a+1,a+1+n);
    long long d=0;
    for (int i=1;i<=n;i++)
    {
        long long bf = b/a[i].first;
        if (bf<a[i].second)
        {
            d+=bf;
            b-=a[i].first*bf;
        }
        else
        {
            d+=a[i].second;
            b-=a[i].first*a[i].second;
        }
    }
    cout << d;
    return 0;
}
