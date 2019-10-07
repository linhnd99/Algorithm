#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int q;

    cin >> q;
    while (q--)
    {
        int n;
        long long a[101];
        cin >> n;
        long long s=0;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            s+=a[i];
        }
        if (s%n==0) cout << s/n << endl;
        else cout << s/n+1 << endl;
    }
    return 0;
}
