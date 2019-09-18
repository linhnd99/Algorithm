#include <bits/stdc++.h>
#define maxn 123456
using namespace std;
int f[maxn][3];
int n,l,r,Q1,Q2,a[maxn];

int nextIndex(int x, bool is)
{
    //is = true : left first
    if (is)
    {
        if (x<=n/2) return n-x+1;
        else return n-x+2;
    }
    else
    {
        if (x<=n/2) return n-x;
        else return n-x+1;
    }
}

long long res(bool chk)
{
    //Left first
    if (chk)
    {
        int i=1;
        f[1][1]=a[1]*l;
        f[1][2]=a[1]*r;
        int d=1;
        cout << i << endl;
        while (d<n)
        {
            int j=nextIndex(i,chk);
            cout << j <<endl;
            f[j][1]=min(f[i][1]+a[j]*l+Q1,f[i][2]+a[j]*r);
            f[j][2]=min(f[i][1]+a[j]*l,f[i][2]+a[j]*r+Q2);
            i=j;
            d++;
        }
        return min(f[i][1],f[i][2]);
    }
    else //right first
    {
        int i=n;
        f[n][1]=a[n]*l;
        f[n][2]=a[n]*r;
        int d=1;
        cout << i<<endl;
        while (d<n)
        {
            int j=nextIndex(i,chk);
            cout << j << endl;
            f[j][1]=min(f[i][1]+a[j]*l+Q1,f[i][2]+a[j]*r);
            f[j][2]=min(f[i][1]+a[j]*l,f[i][2]+a[j]*r+Q2);
            i=j;
            d++;
        }
        return min(f[i][1],f[i][2]);
    }
}
int main()
{
    cin>>n>>l>>r>>Q1>>Q2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
//    f[1][1]=a[1]*l;
//    f[1][2]=a[1]*r;
//    for(int i=2;i<=n;i++)
//        for(int j=1;j<=2;j++)
//        {
//            if(j==1)
//            {
//                f[i][j]=min(f[i-1][j]+a[i]*l+Q1,f[i-1][j]+a[i]*r);
//            }
//            else
//                f[i][j]=min(f[i-1][j]+a[i]*l,f[i-1][j]+a[i]*r+Q2);
//        }
//    cout<<min(f[n][1],f[n][2]);
    long long res_left_first = res(true);
    cout << "left" << endl;
    for (int j=1;j<=2;j++)
    {
        for (int i=1;i<=n;i++) cout << f[i][j]<< " ";
        cout<<endl;
    }
    long long res_right_first = res(false);
    cout << "right" << endl;
    for (int j=1;j<=2;j++)
    {
        for (int i=1;i<=n;i++) cout << f[i][j]<< " ";
        cout<<endl;
    }
    cout << res_left_first << " "<< res_right_first<<endl;
    cout << min(res_left_first,res_right_first);
    return 0;
}
