#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a[10],h;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> h;
    sort(a,a+4);
    if (a[3]+a[2]+a[1]>=h) cout << "WAW";
    else cout << "AWW";
    return 0;
}
