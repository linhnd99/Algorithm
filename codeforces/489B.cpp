#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[1001],b[1001];


int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    cin >> m;
    for (int i=1;i<=m;i++)
        cin >> b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int first=1, second=1,res=0;
    while (first <=n && second <= m)
    {
        if (abs(a[first]-b[second]) <= 1)
        {
            //cout << a[first] << " " << b[second] << endl;
            first ++;
            second ++;
            res ++;
        }
        else if (a[first]<b[second]) first ++;
        else second++;
    }
    cout << res << endl;
    return 0;
}
