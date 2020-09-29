#include <bits/stdc++.h>

using namespace std;

long long t,x;

bool check(long long x)
{
    long long temp = sqrt(x);
    return (temp*temp==x);
}

long long res(long long x)
{
    if (x==1) return 0;
    if (check(x)) {
        return 2*(sqrt(x)-1);
    }
    else {
        long long temp = sqrt(x);
        return 2*(temp-1)+(x-temp*temp)/temp+((x-temp*temp)%temp==0?0:1);
    }
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> x;
        cout << res(x)<<endl;
    }
    return 0;
}
