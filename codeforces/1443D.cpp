#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[200001];

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
        }

        bool isOK=true;
        long long h=0;
        for (int i=n-1;i>=1;i--)
            if (a[i]>=a[i+1]) h+=a[i]-a[i+1];
            else if (a[i]-h<0)
            {
                isOK=false;
                break;
            }
        cout << (isOK?"YES":"NO")<<endl;
    }
}

