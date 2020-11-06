#include <bits/stdc++.h>

using namespace std;

int t;
int n;
pair<long long, long long> a[200001];

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> a[i].first;
        for (int i=1;i<=n;i++)
            cin >> a[i].second;

        sort(a+1,a+1+n);

        long long res = a[n].first;
        long long sum=0;
        for (int i=n;i>=1;i--)
        {
            sum+=a[i].second;
            res = min(res,max(a[i-1].first,sum));
        }
        cout << res<<endl;
    }
}
