#include <bits/stdc++.h>
#define lim 100000000000000
#define PI 3.14159265358979323
using namespace std;

long long n;
long long a[10];

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i=0;i<=n;i++)
            cin >>a[i];

        if (n==3)
        {
            double delta = a[1]*a[1]-3*a[0]*a[2];
            if (delta>0)
            {
                double k = (9*a[0]*a[1]*a[2]-2*a[1]*a[1]*a[1]-27*a[0]*a[0]*a[3])/(2*pow(delta,1/3));
                if (abs(k)<=1)
                {
                    double x1=(2*sqrt(delta)*cos(acos(k)/3)-a[1])/(3*a[0]);
                    double x2=(2*sqrt(delta)*cos(acos(k)/3 - 2*PI/3)-a[1])/(3*a[0]);
                    double x3=(2*sqrt(delta)*cos(acos(k)/3 + 2*PI/3)-a[1])/(3*a[0]);
                    long long rx1,rx2,rx3;
                    if (x1-(long long)x1 <=0.0000001) rx1=(long long)x1;
                    else rx1=lim;
                    if (x2-(long long)x2 <=0.0000001) rx2=(long long)x2;
                    else rx2=lim;
                    if (x3-(long long)x3 <=0.0000001) rx3=(long long)x3;
                    else rx3=lim;

                    cout << min(rx1,min(rx2,rx3))<<endl;
                }
                else
                {
                    cout << (long long)((sqrt(delta)*abs(k))/(3*a[0]*k) * (pow((abs(k)+ sqrt(k*k-1)),1.3) + pow((abs(k)-sqrt(k*k-1)),1.3)) -(a[1]/(3*a[0])));
                }
            }
            else if (delta==0)
            {
                if (a[1]*a[1]*a[1]-27*a[0]*a[3] == 0)
                    cout << (long long)(-a[1]/(3*a[0]));
                else
                    cout << (long long)((-a[1]+pow(a[1]*a[1]*a[1] - 27*a[0]*a[0]*a[3],1.3))/(3*a[0]));
            }
            else
            {
                double k = (9*a[0]*a[1]*a[2]-2*a[1]*a[1]*a[1]-27*a[0]*a[0]*a[3])/(2*pow(delta,1/3));
                cout << (long long)(sqrt(abs(delta))/(3*a[0]) *
                                    ( sqrt(k+pow(k*k+1,1/3) + sqrt(k-pow(k*k+1,1/3))
                                          - a[1]/(3*a[0]))));
            }
        }
        else if (n==2)
        {

            double delta = a[1]*a[1]-4*a[0]*a[2];
            if (delta == 0) cout << - a[1]/(2*a[0]);
            else cout << (-a[1]-sqrt(delta))/(2*a[0]);
        }
        else if (n==1)
        {
            cout << -a[1]/a[0];
        }
        cout << endl;
    }
    return 0;
}
