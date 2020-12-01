#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int> a[1001];

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i].first >> a[i].second;
    sort(a+1,a+1+n);

    int res=1,l=a[1].first,r=a[1].second, index=2;
    while (index<=n)
    {
        if (l<=a[index].first && a[index].first<=r)
        {
            l=max(a[index].first,l);
            r=min(a[index].second,r);
        }
        else
        {
            res++;
            l=a[index].first;
            r=a[index].second;
        }
        index++;
    }
    cout << res<<endl;
    return 0;
}
