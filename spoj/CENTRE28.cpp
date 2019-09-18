#include <bits/stdc++.h>

using namespace std;

vector <pair<int,int> > a[30001];
int n,m;

void dijkstra(int u, int f[], int g[])
{
    queue <int> q;
    q.push(u);
    f[u]=0;
    g[u]=1;
    while (!q.empty())
    {
        u = q.top();
        q.pop();
        for (int i=0;i<a[u].size();i++)
            if (f[u]+a[u][i].second < f[a[u][i].first])
    }
}

int main()
{
    freopen("f.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y,z));
        a[y].push_back(make_pair(x,z));
    }
    dijkstra(1);

}
