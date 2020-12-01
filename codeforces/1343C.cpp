#include <bits/stdc++.h>

using namespace std;

int t;
long long a[200001],n;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> a[i];
        long long cur = a[1];
        long long s=0;
        for (int i=2;i<=n;i++)
            if ((cur>0 && a[i]>0) || (cur<0 && a[i]<0))
                cur = max(cur,a[i]);
            else
            {
                s+=cur;
                cur=a[i];
            }
        s+=cur;
        cout << s <<endl;
    }
}
