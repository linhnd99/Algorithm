#include <bits/stdc++.h>

using namespace std;

long long a[1000001],b[1000001],n,m,k;
long long d=0;

long long bs(long long x, long long l, long long r)
{
    while (l<=r)
    {
        long long mid = (l+r)/2;
        if (x<=a[mid]) r=mid-1;
        else l=mid+1;
    }
    return r;
}

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (long long i=1;i<=n;i++)
        cin >> a[i];
    for (long long i=1;i<=m;i++)
        cin >> b[i];
    sort(a+1,a+1+n);
    vector <long long> v;
    for (int i=1;i<=n;i++) v.push_back(a[i]);
    //cout << bs(3,1,n);

    for (long long i=1;i<=m;i++)
        if (b[i]==0)
        {
            if (k==0) d+=n;
        }
        else if (k%b[i]==0)
        {
            long long vtleft = lower_bound(v.begin(),v.end(),k/b[i])-v.begin()+1;
            long long vtright = lower_bound(v.begin(),v.end(),k/b[i]+1)-v.begin();
            d+=max((long long)0,vtright-vtleft+1);
            //cout << b[i] << " "<< vtright<< " " <<vtleft<<endl;
        }
    cout << d;
}
