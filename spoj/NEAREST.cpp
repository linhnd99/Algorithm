#include <bits/stdc++.h>

using namespace std;

int n;
pair<double,double> a[100001];

double sqr(double x)
{
    return x*x;
}

double distance(pair<double,double> x, pair<double,double> y)
{
    return sqrt(sqr(x.first-y.first) + sqr(x.second-y.second));
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
        cin>> a[i].first >> a[i].second;
    sort(a+1,a+1+n);
    double ma = 10000000000;
    int loop = 100000000/n;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=min(n,i+loop);j++)
            ma=min(ma,distance(a[i],a[j]));
    printf("%0.3lf",ma);
    return 0;
}
