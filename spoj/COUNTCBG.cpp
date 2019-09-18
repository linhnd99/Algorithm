#include <bits/stdc++.h>

using namespace std;

int n;

bool isN(double n)
{
    long long nn=n;
    if (nn-n==0) return true;
    return false;
}

bool check(int A, int B)
{
    double b = (A+B-1)/2.0;
    double a = (-A+B-1)/2.0;
    if (!isN(b) || !(isN(a)) || a<0 || b<0) return false;
    //cout << "a"<<a<<" b" <<b<<endl;
    return true;
}

int f(int X)
{
    X=X*2;
    int d=0;
    for (int i=2;i<=sqrt(X);i++)
        if (X%i==0)
        {
            bool kt = check(i,X/i);
            if (kt)
            {
                //cout << i << " " <<X/i<<endl;
                d++;
            }
        }
    return d;
}

int main()
{
    //freopen("f.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while (cin>>n)
    {
        cout << f(n)<<endl;
    }
    return 0;
}
