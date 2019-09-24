#include <bits/stdc++.h>
#define maxn 123456
using namespace std;
int f[maxn][3];
int n,l,r,Q1,Q2,a[maxn];
int main()
{
    cin>>n>>l>>r>>Q1>>Q2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    f[1][1]=a[1]*l;
    f[1][2]=a[1]*r;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=2;j++)
        {
            if(j==1)
            {
                f[i][j]=min(f[i-1][1]+a[i]*l+Q1,f[i-1][2]+a[i]*r);
            }
            else
                f[i][j]=min(f[i-1][1]+a[i]*l,f[i-1][2]+a[i]*r+Q2);
        }
    cout<<min(f[n][1],f[n][2]);
}
