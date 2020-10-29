#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000+7;
long long n,a[123456];

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+1+n);

    long long s=1;
    for (int i=1;i<=n;i++)
    {
        s=s*(a[i]-i+1)%MOD;
        if (s==0) break;
    }
    cout << s;
    return 0;
}
