#include <bits/stdc++.h>

using namespace std;

long long L1,L2,L3,C1,C2,C3,n,FF,SS,F,S;
long long f[100001],a[100001];

int main()
{
    freopen("f.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3;
    long long d = max(L1,max(L2,L3));
    cin >> n;
    cin >> S >> F;
    for (int i=1;i<n;i++)
    {
        cin >> a[i];
        if (S==i+1) SS = a[i];
        if (F==i+1) FF = a[i];
        f[i]=0;
    }
    a[n]=0;
    f[n]=0;
    sort(a+1,a+n+1);
    //for (int i=1;i<=n;i++) cout << a[i] << " ";cout<<endl;
    for (int i=1;i<=n;i++)
    {
        if (SS==a[i]) S=i;
        if (FF==a[i]) F=i;
    }
    for (int i=min(S,F)+1; i<=max(F,S);i++)
        f[i]=10000000000000000;
    //cout << SS << " " << FF<<endl;
    for (int i=min(S,F)+1; i<=max(F,S);i++)
    {
        int j=i-1;
        while (a[i]-a[j]<=d && j>0)
        {
            if (a[j]+L1>=a[i] && f[j]+C1<f[i])
            {
                f[i]=f[j]+C1;
                //cout <<"."<<L1<<"."<<a[j]+L1<<"."<<j<<". ";
            }
            if (a[j]+L2>=a[i] && f[j]+C2<f[i]) f[i]=f[j]+C2;
            if (a[j]+L3>=a[i] && f[j]+C3<f[i]) f[i]=f[j]+C3;
            //cout << j<< " " <<i<<" " <<f[i] << endl;
            j--;
        }
    }
    //for (int i=1;i<n;i++) cout << f[i] << " ";cout<<endl;
    cout << f[max(F,S)];
    return 0;
}
