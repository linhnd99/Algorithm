#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long n,x,a,b;
        cin >> n >> x >> a >> b;
        if (a>b) swap(a,b);
        if (b+x<=n)
        {
            b+=x;
            x=0;
        }
        else
        {
            x-=(n-b);
            b=n;
        }
        if (a-x>=1)
        {
            a-=x;
            x=0;
        }
        else a=1;
        cout << b-a<<endl;
    }
}
