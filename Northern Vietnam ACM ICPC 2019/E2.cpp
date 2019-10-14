#include <bits/stdc++.h>
#define limX 30001
#define limY 10000000000000000

using namespace std;

int T;
long long a[10],n;

long long f(long long x)
{
    return a[0]*x*x*x+a[1]*x*x+a[2]*x+a[3];
}

long long chat(long long l, long long r)
{
    if (f(l)*f(r)>0) return limY;
    while (l<=r)
    {
        //cout << l << " " << f(l)<< " " << r << " " <<f(r)<<endl;
        long long mid = (l+r)/2;
        //cout << mid << " " << f(mid)<< endl;
        if (f(mid) == 0) return mid;
//        if (f(l)==0) return l;
//        if (f(r)==0) return r;
//        if (f(mid+1)==0) return mid+1;
//        if (f(mid-1)==0) return mid+1;
        if ((f(l)<0 && f(mid)>0) || (f(l)>0 && f(mid)<0)) r=mid-1;
        else l=mid+1;
    }
    return limY;
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> T;
    while(T--)
    {
        cin >> n;
        for (int i=0;i<=n;i++)
            cin >> a[i];
        if (n==3)
        {
            long long  delta_ = a[1]*a[1] - 3*a[2]*a[0];
            //cout << delta_<<endl;
            if (delta_ == 0)
            {
                long long  nghiem1=chat(-limX,-a[1]/(3*a[0]));
                long long  nghiem2=chat(-a[1]/(3*a[0]),limX);
                cout <<min(nghiem1,nghiem2)<<endl;
            }
            else if (delta_ >0)
            {
                long long  x1 = (-a[1]-sqrt(delta_))/(3*a[0]);
                long long  x2 = (-a[1]+sqrt(delta_))/(3*a[0]);
                long long  nghiem1=chat(-limX,x1-1);
                long long  nghiem2=chat(x1,x2);
                long long  nghiem3=chat(x2+1,limX);
                //cout << a[1]<< " " << a[0] << " " <<delta_<<endl;
                //cout << x1 << " " << x2<<endl;
                long long  res = min(nghiem1,min(nghiem2,nghiem3));
                if (f(x2)==0) res = min(res,x2);
                if (f(x1)==0) res = min(res,x1);
                cout << res << endl;
            }
            else
            {
                cout <<chat(-limX,limX) <<endl;
            }
        }
        else if (n==2)
        {
            long long delta =a[1]*a[1]-4*a[0]*a[2];
            if (delta>0)
            {
                cout << (-a[1]-sqrt(delta))/(2*a[0])<<endl;
            }
            else //delta==0
            {
                cout << -a[1]/(2*a[0])<<endl;
            }
        }
        else if (n==1)
        {
            cout << -a[1]/a[0]<<endl;
        }
    }
}
