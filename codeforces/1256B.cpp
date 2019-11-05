#include <bits/stdc++.h>

using namespace std;

int q,n,a[1001];

int main()
{
    //freopen("F.INP","r",stdin);
    cin >> q;
    while(q--)
    {
        bool kt[1001]={};
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        int d=n-1;
        int j=0;
        int vt=1;
        while (d>=1 && vt<=n)
        {
            //cout <<"!"<<vt<<endl;
            for (int i=vt+1;i<=n;i++)
                if (a[vt]>a[i] && kt[i]==false) vt=i;
            for (int i=vt;i>1;i--)
                if (kt[i]==false && a[i]<a[i-1])
                {
                    swap(a[i],a[i-1]);
                    d--;
                    kt[i]=true;
                    if (d==0) break;
                }
                else break;
            kt[vt]=true;
            vt++;
        }
        for (int i=1;i<=n;i++) cout << a[i]<< " ";cout<<endl;
    }
}
