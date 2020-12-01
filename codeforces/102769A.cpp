#include <bits/stdc++.h>

using namespace std;

long long C2(long long y)
{
    return (y*(y-1)/2);
}

int main()
{
    freopen("F.INP","r",stdin)
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> testcase;
    for (int i=1;i<=testcase;i++)
    {
        cin >> a >> b;
        long long sum = C2(a)+a*b+C2(b);
        long long res = C2(a);
        long long gcd = __gcd(res,sum);
        cout << "Case #"<<i<<": " << res/gcd <<"/"<< sum/gcd << endl;
    }
    return 0;
}
