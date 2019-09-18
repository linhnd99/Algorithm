#include <bits/stdc++.h>

using namespace std;
int n,m;
vector <pair<int,int> > a;
int b[1000001];

int bs(int x, int l, int r)
{
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (x<a[mid].first) r=mid-1;
        else l=mid+1;
    }
    return l-1;
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a.push_back(make_pair(x,i));
    }
    for (int i=1;i<=m;i++)
        cin >> b[i];
    sort(a.begin(),a.end());
    //for (int i=0;i<n;i++) cout<<a[i].first<< " "<<a[i].second<<endl;
    //cout << bs(1,0,n-1)+1;
    for (int i=1;i<=m;i++)
    {
        int vt = bs(b[i],0,n-1);
        //cout << vt << endl;
        cout << vt+1 << " ";
    }
    return 0;
}
