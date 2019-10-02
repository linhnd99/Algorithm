#include <bits/stdc++.h>

using namespace std;

int h(int x, int y)
{
    return abs(x-y);
}

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n,a[501],b[501];
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> a[i];
        for (int i=1;i<=n;i++)
            cin >> b[i];
        int fa[501],fb[501];
        for (int i=1;i<=n;i++)
        {
            fa[i]=fa[i-1]+a[i];
            fb[i]=fb[i-1]+b[i];
        }
        pair<int,int> f[2][501];
        f[1][1].first = b[1];
        f[1][1].second = a[1];
        f[0][1].first = a[1];
        f[0][1].second = b[1];
        for (int i=2;i<=n;i++)
        {
            int sa,sb,mi;
            // neu khong doi
            if (h(f[0][i-1].first + a[i],f[0][i-1].second + b[i]) < h(f[1][i-1].first + a[i],f[1][i-1].second + b[i]))
            {
                f[0][i].first = f[0][i-1].first+a[i];
                f[0][i].second = f[0][i-1].second+b[i];
            }
            else
            {
                f[0][i].first = f[1][i-1].first+a[i];
                f[0][i].second = f[1][i-1].second+b[i];
            }
            //neu doi
            if (h(f[0][i-1].first+b[i],f[0][i-1].second+a[i]) < h(f[1][i-1].first+b[i],f[1][i-1].second+a[i]))
            {
                f[1][i].first = f[0][i-1].first+b[i];
                f[1][i].second = f[0][i-1].second+a[i];
            }
            else
            {
                f[0][i].first = f[1][i-1].first+b[i];
                f[0][i].second = f[1][i-1].second+a[i];
            }
//            f[1][i].first = f[1][i].first+b[i];
//            f[1][j].second = f[i][j].second+a[i];
            for (int j=1;j<i;j++)
            {
                //neu khong doi
                if (h(f[0][i].first,f[0][i].second) > h(f[0][j].first+(fa[i]-fa[j]),f[0][j].second+(fb[i]-fb[j])))
                {
                    f[0][i].first = f[0][j].first + (fa[i]-fa[j]);
                    f[0][i].second = f[0][j].second + (fb[i]-fb[j]);
                }
                if (h(f[1][i].first,f[1][i].second) > h(f[1][j].first+(fa[i]-fa[j]),f[1][j].second+(fb[i]-fb[j])))
                {
                    f[1][i].first = f[1][j].first + (fa[i]-fa[j]);
                    f[1][i].second = f[1][j].second + (fb[i]-fb[j]);
                }
                //neu doi
                if (h(f[0][i].first,f[0][i].second) > h(f[0][j].first+(fb[i]-fb[j]),f[0][j].second+(fa[i]-fa[j])))
                {
                    f[0][i].first = f[0][j].first + (fb[i]-fb[j]);
                    f[0][i].second = f[0][j].second + (fa[i]-fa[j]);
                }
                if (h(f[1][i].first,f[1][i].second) > h(f[1][j].first+(fb[i]-fb[j]),f[1][j].second+(fa[i]-fa[j])))
                {
                    f[1][i].first = f[1][j].first + (fb[i]-fb[j]);
                    f[1][i].second = f[1][j].second + (fa[i]-fa[j]);
                }
//
//                f[1][j].first+(fb[i]-fb[j])
//                f[1][j].second+(fa[i]-fa[j])
//                vs
//                f[0][j].first+fa[i]-fa[j];
//                f[0][j].second+fb[i]-fb[j];
            }
        }
        cout <<"000"<<endl;
        for (int i=1;i<=n;i++)
            cout << f[0][i].first << " " <<f[0][i].second << endl;
        cout <<"111"<<endl;
        for (int i=1;i<=n;i++)
            cout << f[1][i].first << " " <<f[1][i].second << endl;
        if (h(f[1][n].first,f[1][n].second) < h(f[0][n].first,f[0][n].second))
            cout << f[1][n].first<< " " << f[0][n].second<<endl;
        else cout << f[1][n].first<< " " << f[0][n].second<<endl;
    }

    return 0;
}
