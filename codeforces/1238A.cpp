#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        long long a,b;
        cin >> a >> b;
        if (a-b==0 || a-b==1) cout << "NO"<<endl;
        else cout <<"YES"<<endl;
    }
}
