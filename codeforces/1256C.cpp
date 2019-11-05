#include <bits/stdc++.h>

using namespace std;

int n,m,d,c[1003],res[1003];

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> d;
    int s=0;
    for (int i=1;i<=m;i++)
    {
        cin >> c[i];
        s+=c[i];
    }
    s=n-s;
    int vt=0;
    int first=1;
    while (vt<=n && first<=m)
    {
        if (s>0)
        {
            if (d<=s)
            {
                res[vt+d]+=first;
                res[vt+d+c[first]]-=first;
                s=s-d+1;
                vt=vt+d+c[first]-1;
                first++;
                vt--;
            }
            else //s<d
            {
                res[vt+s+1]+=first;
                res[vt+s+c[first]+1]-=first;
                vt=vt+s+c[first]+1;
                first++;
                s=0;
                vt--;
            }
        }
        else
        {
            if (vt==0)
            {
                res[vt+1]+=first;
                res[vt+1+c[first]]-=first;
                vt=vt+c[first];
                first++;
            }
            else
            {
                res[vt]+=first;
                res[vt+c[first]]-=first;
                vt=vt+c[first]-1;
                first++;
            }
        }
        vt++;
    }
    if (vt+d<=n)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES"<<endl;
    //for (int i=1;i<=n;i++) cout << res[i] << " ";cout<<endl;
    for (int i=1;i<=n;i++)
        res[i]=res[i-1]+res[i];
    for (int i=1;i<=n;i++)
        cout << res[i] << " ";
    return 0;
}
