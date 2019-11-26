#include <bits/stdc++.h>

using namespace std;

int n,t;
pair <long long,long long> a[1000001];
int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;

        long long mi=1000000001,ma=0;
        for (int i=1;i<=n;i++)
        {
            cin >>a[i].first >> a[i].second;
            ma=max(a[i].first,ma);
            mi=min(a[i].second,mi);
        }
        if (n==1 || ma<=mi) cout <<0<<endl;
        else cout << ma-mi<<endl;
    }
    return 0;
}
