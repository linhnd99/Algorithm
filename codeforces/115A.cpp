#include <bits/stdc++.h>

using namespace std;

vector<int> a[2001];
int n;
int level[2001];
bool check[2001];


void bfs(int u)
{
    queue <int> q;
    q.push(u);
    level[u]=1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        check[u]=true;
        for (int i=0;i<a[u].size();i++)
        {
            level[a[u][i]] = level[u]+1;
            q.push(a[u][i]);
        }
    }
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a[x].push_back(i);
    }

    for (int i=1;i<=n;i++)
        if (!check[i])
        {
            bfs(i);
        }
    int res = 0;
    for (int i=1;i<=n;i++)
    {
        res = max (res,level[i]);
    }
    cout << res << endl;
}
