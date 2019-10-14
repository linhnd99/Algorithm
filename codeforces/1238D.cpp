#include <bits/stdc++.h>

using namespace std;

long long f[100001];
long long n;
string s;

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    cin >> s;

    long long res=0;
    if (s[0]=='A') f[0]=1;
    else f[0]=0;
    for (int i=1;i<n;i++)
        if (s[i]=='A') f[i]=f[i-1]+1;
        else f[i]=0;
    for (int i=1;i<n;i++)
        if (f[i]==0)
        {
            res+=f[i-1];
        }
    if (f[n-1]!=1 && f[n-1]!=n) res+=f[n-1];
    cout << n*(n-1)/2-res<<endl;


    if (s[0]=='B') f[0]=1;
    else f[0]=0;
    for (int i=1;i<n;i++)
        if (s[i]=='B') f[i]=f[i-1]+1;
        else f[i]=0;
    for (int i=1;i<n;i++)
        if (f[i]==0)
        {
            res+=f[i-1];
            //cout << i << " "<<f[i-1]<<endl;
        }
    //for (int i=0;i<n;i++) cout << f[i]<< " ";cout<<endl;
    if (f[n-1]!=1 && f[n-1]!=n) res+=f[n-1];
    cout << n*(n-1)/2-res;
    return 0;
}
