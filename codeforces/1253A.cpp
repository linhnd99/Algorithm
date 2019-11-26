#include <bits/stdc++.h>

using namespace std;

    long long  n,t;
    long long a[100001],b[100001];

int main()
{
    //freopen("F.INP","r",stdin);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> a[i];
        for (int i=1;i<=n;i++)
            cin >> b[i];
        for (int i=1;i<=n;i++)
            a[i]=b[i]-a[i];
        int d=0;
        a[0]=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]<0)
            {
                d=100;
                break;
            }
            if (a[i-1]==0 && a[i]!=0) d++;
            else if (a[i-1]!=a[i] && a[i]!=0 && a[i-1]!=0) d=100;
        }

        if (d>1)
            cout <<"NO"<<endl;
        else cout << "YES"<<endl;
    }
    return 0;
}
