#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    long long q,a,b,n,s;
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> n >> s;
        if (a*n+b>=s && s%n<=b) cout <<"YES"<<endl;
        else cout <<"NO"<<endl;
    }
    return 0;
}
