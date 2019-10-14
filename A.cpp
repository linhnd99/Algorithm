#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001];

int main()
{
    //freopen("F.INP","r",stdin);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >>a[i];
    sort(a+1,a+1+n);
    if (a[1]>1)
        for (int i=1;i<a[1];i++) cout << i<<endl;
    for (int i=1;i<=n-1;i++)
    {
        for (int j=a[i]+1;j<a[i+1];j++)
        {
            cout << j << endl;
        }
    }
    if (a[n]==n) cout <<"good job";
    return 0;
}
