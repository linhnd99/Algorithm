#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ll t, d, k;

int main(int argc, char const *argv[])
{
    iosb;
    freopen("F.INP", "r", stdin);
    cin>>t;
    while(t--)
    {
        ll ans = 0;
        cin>>d>>k;
        for(int i=k;i<=d; i+=k)
        {
            ll tmp = (ll)(sqrt(d*d-i*i));
            ans+=tmp/k+1;
        }
        ans*=3;
        ans+=d/k;
        cout << ans;
        if(ans%2==0)
            cout<<"Ashish"<<endl;
        else
            cout<<"Utkarsh"<<endl;
    }
    return 0;
}
