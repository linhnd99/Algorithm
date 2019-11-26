#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,T,b;
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        if (a>b) swap(a,b);
        if (a==b)
        {
            cout <<0<<endl;
            continue;
        }
        a=b-a;
        long long res = a/5+(a%5 /2)+a%5%2;
        cout << res<<endl;
    }
    return 0;
}
