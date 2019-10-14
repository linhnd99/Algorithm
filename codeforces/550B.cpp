#include <bits/stdc++.h>

using namespace std;

long long n,l,r,x,d;
long long a[100],p[100];
bool kt[100];
long long sum;

void backtrack(int i)
{
    for (int j=1;j<=n;j++)
        if (kt[j]==false);
        {
            p[i]=a[j];
            kt[j]=true;
            if (i==n)
            {
                long long s=0;
                for (int k=1;k<=n;k++)
                    if
            }
        }
}

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> l >> r >> x;
    for (int i=1;i<=n;i++)
        cin >>a[i];
    sort(a+1,a+1+n);

    d=0;
    sum=0;
    backtrack(1);
    cout << d;
}
