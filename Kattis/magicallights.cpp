#include <bits/stdc++.h>

using namespace std;

map<int,int> c[300001];
int tree[300001],color[300001],par[300001];
int n,q;

void build()
{
    for (int i=n;i>=1;i--)
    {
        int x = i;

        c[x][color[x]]++;

        for (int xc = 1; xc<=100;xc++)
        {
            c[par[x]][xc] = c[x][xc];
            if (c[x][xc]%2==1)
            {
                tree[x]++;
            }
        }
    }
}

int query(int x)
{
    return tree[x];
}

int update(int x, int newColor)
{
    int point = x;
    while (point > 0)
    {
        c[point][color[x]]--;
        if (c[point][color[x]] %2 == 1)
            tree[point]++;
        else tree[point]--;
        point=par[point];
    }

    color[x]=newColor;

    point=x;
    while (point > 0)
    {
        c[point][color[x]]++;
        if (c[point][color[x]] %2 == 1)
            tree[point]++;
        else tree[point]--;
        point=par[point];
    }
}

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++)
        cin >> color[i];
    par[1]=0;
    for (int i=2;i<=n;i++)
        cin >> par[i];

    build();

    while (q--)
    {
        int w,ww;
        cin >> w >> ww;
        if (w==0)
        {
            cout << query(ww)<<endl;
        }
        else
        {
            update(ww,w);
        }
    }
    return 0;
}
