#include <bits/stdc++.h>

using namespace std;



int main()
{
    freopen("RUBIC.INP","r",stdin);
    freopen("RUBIC.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long a[31][31][31], tongTrai[31][31][31]={},tongTren[31][31][31]={};
        int n;

        cin >> n;
        for (int z=1;z<=n;z++)
        {
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                     cin >> a[i][j][z];
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                for (int z=1;z<=n;z++)
                    tongTrai[i][j][z]=tongTrai[i][j-1][z]+a[i][j][z];
            }

        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int z=1;z<=n;z++)
                    tongTren[i][j][z]=tongTren[i-1][j][z]+tongTrai[i][j][z];
//        for (int i=1;i<=n;i++)
//        {
//            for (int j=1;j<=n;j++)
//                cout <<tongTren[i][j][1]<< " " ;
//            cout<<endl;
//        }
        long long ma=-LONG_LONG_MAX;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                for (int z=1;z<=n;z++)
                {
                    //tongTren[i+len][j+len][z] - tongTren[i-1][j][z] - tongTren[i][j-1][z] + tongTren[i-1][j-1][z]
                    long long s = 0;
                    for (int len=1;len<=min(n-i+1,min(n-j+1,n-z+1));len++)
                    {
                        s=0;
                        for (int k=1;k<=len;k++)
                            s+=tongTren[i+len-1][j+len-1][z+k-1]
                                - tongTren[i-1][j+len-1][z+k-1]
                                - tongTren[i+len-1][j-1][z+k-1]
                                + tongTren[i-1][j-1][z+k-1];
                        if (ma<s) ma=s;
                    }
                    //cout <<i<< " " << j<<" " << z<< " "<<min(n-i+1,min(n-j+1,n-z+1)) << " :) "<<s<<endl;
                }
            }
        cout << ma << endl;
        //cout <<tongTren[2+2-1][2+2-1][1] - tongTren[2-1][2+2-1][1] - tongTren[2+2-1][2-1][1] + tongTren[2-1][2-1][1]<<endl;
        //cout <<tongTren[2+2-1][2+2-1][2] - tongTren[2-1][2+2-1][2] - tongTren[2+2-1][2-1][2] + tongTren[2-1][2-1][2]<<endl;
        //cout <<tongTren[1+3-1][1+3-1][3] - tongTren[1-1][1+3-1][3] - tongTren[1+3-1][1-1][3] + tongTren[1-1][1-1][3]<<endl;
    }
    return 0;
}

