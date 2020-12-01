#include <bits/stdc++.h>


using namespace std;

//const long long MOD = 1000000000+7;
const long long MOD = 31;
const int N = 10000;
long long a[N+1];
void pre()
{
    a[1]=1;
    a[2]=1;
    for (int i=3;i<=N;i++)
        a[i]=(a[i-1]+a[i-2])%MOD;
    for (int i=2;i<=N-10;i++)
        if (a[i]==0 && a[i+1]==1 && a[i+2]==1)
        {
            cout << i << " ";
            //break;
        }
    cout << ":))";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    pre();
    return 0;
}
