#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    cout << n/100 + n%100/20 + n%20/10+ n%10/5+n%5;
    return 0;
}
