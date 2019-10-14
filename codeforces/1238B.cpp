#include <bits/stdc++.h>

using namespace std;

int q;
int n,k;
int a[100001];

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        for (int i=1;i<=n;i++)
            cin >> a[i];
        sort(a+1,a+1+n);
        int d=0;
        for (int i=n;i>=1;i--)
        {
            if (a[i]-d*k<=0) break;
            int j=i-1;
            d++;
            while (j>0 && a[j]==a[i])
            {
                j--;
            }
            i=j+1;
        }
        cout << d <<endl;
    }
    return 0;
}
