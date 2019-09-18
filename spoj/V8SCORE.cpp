#include <bits/stdc++.h>

using namespace std;

int p[30],a[30][30];
bool res;
int arr_res[30];
int sum = 0,n,S,k;

void backtrack(int i)
{
    if (res) return ;
    if (sum>S) return ;
    for (int j=1;j<=n;j++)
        if (p[i-1]<=a[j][i])
        {
            //cout << i<<"vs"<<j<<endl;
            p[i]=a[j][i];
            sum+=a[j][i];
            if (i==k)
            {
                //for (int ii=1;ii<=k;ii++) cout << p[ii]<< " ";cout<<endl;
                if (sum == S)
                {
                    res=true;
                    for (int i1=1;i1<=k;i1++) arr_res[i1]=p[i1];
                    return;
                }
            }
            else
                backtrack(i+1);
            sum-=a[j][i];
        }
}

int main()
{
    //freopen("f.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> S >> k >> n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=k;j++)
            cin >> a[i][j];

    res = false;
    p[0]=0;
    sum=0;
    backtrack(1);
    if (res)
    {
        cout << "YES"<<endl;
        for (int i=1;i<=k;i++) cout << arr_res[i] << " ";
    }
    else cout << "NO";
    return 0;
}
