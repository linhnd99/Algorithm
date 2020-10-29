#include <bits/stdc++.h>

using namespace std;

typedef pair<long long,long long> pii;
const long long MAX = 10000000000000+7;
long long a[1001][1001],d[1001][1001],b[1000001];
int n,m;

void dijkstra(int s)
{
    // Khoi tao
    for (int i=0;i<=n;i++)
        d[s][i]=MAX;

    // Dijkstra
    //priority_queue<pii, vector<pii>, greater<pii> > pq;
    priority_queue<pii> pq;
    pq.push(make_pair(0,s));
    d[s][s]=0;
    while (!pq.empty())
    {
        pii u = pq.top();
        pq.pop();
        if (u.first > d[s][u.second]) continue;
        for (int v=1;v<=n;v++)
            if (a[u.second][v]!=0 && d[s][u.second]+a[u.second][v] < d[s][v])
            {
                d[s][v] = d[s][u.second]+a[u.second][v];
                pq.push(make_pair(d[s][v],v));
            }
    }
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++)
        cin >> b[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin >> a[i][j];

    for (int i=1;i<=n;i++)
        dijkstra(i);
//    for (int i=1;i<=n;i++)
//    {
//        for (int j=1;j<=n;j++)
//            cout << d[i][j] << " ";
//        cout << endl;
//    }

    long long s=d[1][b[1]];
    for (int i=1;i<=m-1;i++)
    {
        s+=d[b[i]][b[i+1]];
    }
    cout << s;
    return 0;
}
