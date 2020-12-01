#include <bits/stdc++.h>

using namespace std;

pair<long long,long long> a[10];
int tt;


long long f(pair<long long,long long> x, pair<long long,long long> y, pair<long long,long long> z, pair<long long,long long> t, long long sq)
{
    long long xx = min(abs((sq + x.first+x.second)*4 - (x.first+x.second+y.first+y.second+z.first+z.second+t.first+t.second)),abs((-sq + x.first+x.second)*4 - (x.first+x.second+y.first+y.second+z.first+z.second+t.first+t.second)));
    long long yy = min(abs((sq+y.first+y.second)*4 - (x.first+x.second+y.first+y.second+z.first+z.second+t.first+t.second)),abs((-sq+y.first+y.second)*4 - (x.first+x.second+y.first+y.second+z.first+z.second+t.first+t.second)));
    long long zz = min(abs((sq+z.first+z.second)*4 - (x.first+x.second+y.first+y.second+z.first+z.second+t.first+t.second)),abs((-sq+z.first+z.second)*4 - (x.first+x.second+y.first+y.second+z.first+z.second+t.first+t.second)));
    long long tt = min(abs((sq+t.first+t.second)*4 - (x.first+x.second+y.first+y.second+z.first+z.second+t.first+t.second)),abs((-sq+t.first+t.second)*4 - (x.first+x.second+y.first+y.second+z.first+z.second+t.first+t.second)));
    return min(min(xx,yy),min(zz,tt));
}

long long tsearch(long long l, long long r)
{

    while (l<=r)
    {
        long long mid1=(r-l)/3+l;
        long long mid2=r-(r-l)/3;
        if (f(a[1],a[2],a[3],a[4],mid1) > f(a[1],a[2],a[3],a[4],mid2)) l=mid1+1;
        else r=mid2-1;
    }
    return min(f(a[1],a[2],a[3],a[4],l),f(a[1],a[2],a[3],a[4],r));
}

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> tt;
    while (tt--)
    {
        for (int i=1;i<=4;i++)
            cin >> a[i].first >> a[i].second;
        long long res = tsearch(1,1000000000);
        cout << res << endl;
    }
}
