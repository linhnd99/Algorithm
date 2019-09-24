#include <bits/stdc++.h>
#define maxn 123456

using namespace std;

int f[maxn];
int n,l,r,Ql,Qr,a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r>>Ql>>Qr;
    long long s=0;
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    s=1000000001;
    for (int L=0;L<=n;L++)
    {
        int aa = L;
        int bb = n-L;
        long long rs = f[aa]*l + (f[n]-f[aa])*r + ((aa<bb)?((bb-aa-1)*Qr):(aa-bb-1)*Ql);
        if (aa==bb) rs = f[aa]*l+ (f[n]-f[aa])*r;
        s = min(s,rs);
        //cout << L << " " << rs<<endl;
    }
    cout << s;
    return 0;
}
