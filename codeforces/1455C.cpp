#include <bits/stdc++.h>

using namespace std;

long long n,x,a[1000];

bool isOK()
{
    for (int i=2;i<=n;i++)
        if (a[i-1]>a[i]) return false;
    return true;
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        for (int i=1;i<=n;i++)
            cin >> a[i];
        long long res=0;
        for (int i=1;i<=n;i++)
        {
            if (isOK()) break;
            if (x<a[i])
            {
                swap(x,a[i]);
                res++;
            }
        }

        if (isOK()) cout << res << endl;
        else cout << -1 << endl;
    }
    return 0;
}

