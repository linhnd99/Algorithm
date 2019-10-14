#include <bits/stdc++.h>
#define inf 1e6
using namespace std;
double F(double, x,long long a, long long b, long long c, long long d)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            int x,y;
            cin>>x>>y;
            cout<<-y/x<<endl;
        }
        if(n==2)
        {
            long long a[3];
            cin>>a[0]>>a[1]>>a[2];
            long long delta=a[1]*a[1]-4*a[0]*a[2];
            if(delta>0)
                cout<<min(-a[1]+sqrt(delta)/(2*a[0]),-a[1]-sqrt(delta)/(2*a[0]));
            else
                cout<<-a[1]/(2*a[0])<<endl;

        if(n==3)
        {
            long long a[4];
            cin>>a[0]>>a[1]>>a[2]>>a[3];
            long long delta=a[1]*a[1]-3*a[0]*a[2];
            if(delta>0)
            {
                double x1=-a[1]+sqrt(delta)/a[0];
                double x2=-a[1]-sqrt(delta)/a[0];
                if(F(x1)*F(x2)<0)
                {
                    cout<<min(BS(-inf,min(x1,x2)),min(BS(min(x1,x2),max(x1,x2)),BS(max(x1,x2),inf)))<<endl;
                }
                else
                    if(F(x1)*F(x2)==0)
                        cout<<min(BS)
            }
        }
    }
}
