#include <bits/stdc++.h>

using namespace std;

vector<int> a[100001];
int b[100001],cat[100001];
bool kt[100001]={};
int n,m;
int dem;

void bfs(int u)
{
    queue <int> q;
    q.push(u);
    kt[u]=true;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        if (u!=1 && a[u].size() == 1)
        {
            dem++;
        }
        for (int i=0;i<a[u].size();i++)
            if (kt[a[u][i]] == false)
            {
                kt[a[u][i]]=true;
                if (b[a[u][i]] == 1) cat[a[u][i]]=cat[u]+1;
                else cat[a[u][i]]=0;
                if (cat[a[u][i]]<=m)
                {
                    q.push(a[u][i]);
                }
            }
    }
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> b[i];
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dem=0;
    cat[1] = b[1];
    bfs(1);

    cout << dem<<endl;
    return 0;

}
