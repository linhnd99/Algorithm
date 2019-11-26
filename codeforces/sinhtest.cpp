#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n=30;
    for (int i=1;i<=n;i++)
    {
        cout << i << " "<<(double)(i*i+n*n)/(i+1)<<endl;
    }
    return 0;
}
