#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int a[10];
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    sort(a+1,a+5);
    if (a[1]+a[4]==a[2]+a[3]) cout <<"YES";
    else if (a[1]+a[2]+a[3]==a[4]) cout << "YES";
    else cout <<"NO";
    return 0;
}
