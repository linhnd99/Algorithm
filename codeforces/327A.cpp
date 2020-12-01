#include <bits/stdc++.h>

using namespace std;

int n;
int a[101];
int sum=0,res=0;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    res=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            int s=0;
            for (int k=1;k<=n;k++)
                if (i<=k && k<=j) s=s+1-a[k];
                else s+=a[k];
            res = max (res,s);
        }

    }
    cout << res<<endl;
    return 0;
}
