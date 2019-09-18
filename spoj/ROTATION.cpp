#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    long long n,s;
    cin >> n;
    for (int i=1;i<n;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        s+=z;
    }
    cout << s%2;
    return 0;
}
