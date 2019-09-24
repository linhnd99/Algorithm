#include <bits/stdc++.h>

using namespace std;

pair <int,int> a[300001],b[300001];
int n;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a[i]=make_pair(x,i);
    }
    sort(a+1,a+1+n);
    int mi = min(0,a[1].first);
    for (int i=1;i<=n;i++)
    {
        if (mi<a[i].first)
        {
            b[i]=make_pair(a[i].second,a[i].first);
            mi=a[i].first+1;
        }
        else
        {
            b[i]=make_pair(a[i].second,mi);
            mi++;
        }
    }
    sort(b+1,b+1+n);
    for (int i=1;i<=n;i++)
        cout << b[i].second << " ";
    return 0;
}
