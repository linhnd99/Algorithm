#include <bits/stdc++.h>

using namespace std;

long long C2(long long y)
{
    return (y*(y-1)/2);
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int testcase;
    cin >> testcase;
    for (int i=1;i<=testcase;i++)
    {
        long long a,b;
        cin >> a >> b;
        if (b==1)
        {
            cout<< "Case #"<<i<<": " << a<<endl;
            continue;
        }
        long long x = pow(a,1.0/b);
        long long res = 0,l=1,r=pow(2,b)-1;
        for (int i=1;i<=x;i++)
        {
            if (r>a) r=a;
            if (l>a) l=a;
            res += r/i-l/i+1;
            l=r+1;
            r=pow(i+2,b)-1;
            if (r>a) r=a;
            if (l>a) l=a;
            //cout << i << " " << l/i << " " << r/i << " " << res<< endl;
        }
        cout << "Case #"<<i<<": "<<res << endl;
    }
    return 0;
}

