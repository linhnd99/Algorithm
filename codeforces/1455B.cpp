#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        if (x==1)
        {
            cout << 1 << endl;
            continue;
        }
        long long res = 0,s=0;
        for (int i=1;true;i++)
        {
            res = i;
            s+=i;
            if (s>=x) break;
        }
        if (s-1!=x) cout << res << endl;
        else cout << res+1 << endl;
    }
    return 0;
}
