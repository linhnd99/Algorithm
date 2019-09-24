#include <bits/stdc++.h>
using namespace std;
int main()
{
    int c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    int n,m,B=0,T=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x*c1>=c2)
        {
            B+=c2;
        }
        else
            B+=x*c1;
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        if(x*c1>=c2)
            T+=c2;
        else
            T+=x*c1;
    }
    cout<<min(c4,min(2*c3,min(c3+min(B,T),B+T)));
}
