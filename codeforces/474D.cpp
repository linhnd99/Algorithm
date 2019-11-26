#include <bits/stdc++.h>

const long long mod = 1000000007 ;

using namespace std;

long long CC(long long k, long long n, long long dodaicap)
{
    long long s=1;
    long long soR = n-dodaicap*k;
    long long soVT = soR+k;
    soVT = n-((dodaicap-1)*k);
    cout << soVT<<endl;
    for (long long i=1;i<=k;i++)
    {
        s=(s*soVT)%mod;
        soVT--;
    }
    return s/k;
}

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,k;
    cin >> t >> k;
    cout << CC(3,6,2);
    return 0;
}
