#include <bits/stdc++.h>

using namespace std;

int t,n;
set<int> e;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while (t--)
    {
        e.clear();
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            e.insert(x);
        }
        if (e.size() == n)
            cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
