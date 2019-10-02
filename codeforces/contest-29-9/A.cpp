#include <bits/stdc++.h>

using namespace std;

map<int,int> dic;
int n;
int a[100001],fr[100001],fl[100001];

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    if (n==1)
    {
        cout << 0;
        return 0;
    }
    for (int i=1;i<=n;i++)
        cin >> a[i];

    for (int i=1;i<=n;i++)
    {
        fl[i]=dic[a[i]-1]+1;
        dic[a[i]]=dic[a[i]-1]+1;
    }
    dic.clear();
    for (int i=n;i>=1;i--)
    {
        fr[i]=dic[a[i]-1]+1;
        dic[a[i]]=dic[a[i]-1]+1;
    }
    int ma=0;
    int vt[100001];
    map<int,int> temp;
    for (int i=n;i>=1;i--)
    {
        vt[i]=temp[a[i]];
        temp[a[i]]=i;
    }
//    for (int i=1;i<=n;i++)
//        cout << fr[i] << " " ;cout<<endl;

    for (int i=1;i<=n;i++)
    {
        if (a[i]==a[vt[i]]) ma = max(ma,2*min(fl[i],fr[vt[i]]));
        ma = max (ma, 2*min(fl[i],fr[i])-1);
        //cout << ma << " ";
    }
    //cout << endl;
    cout << n-ma;
    return 0;
}
