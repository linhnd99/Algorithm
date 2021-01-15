#include <bits/stdc++.h>

using namespace std;

int t,n,a[1001],d;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> d;
        for (int i=1;i<=n;i++)
            cin >> a[i];
        sort(a+1,a+1+n);
        if (a[1]+a[2]<=d || a[n]<=d)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
