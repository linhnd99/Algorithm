#include <bits/stdc++.h>

using namespace std;

int m,x,y;
int c[1001],f[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> m;
    for (int i=1;i<=m;i++)
        cin >> c[i];
    cin >> x >> y;
    f[0]=0;
    for (int i=1;i<=m;i++)
        f[i]=f[i-1]+c[i];
    for (int i=1;i<=m;i++)
        if (x<=f[i] && f[i]<=y && x<=f[m]-f[i] && f[m]-f[i]<=y)
        {
            cout << i+1;
            return 0;
        }
    cout << 0;
    return 0;
}
