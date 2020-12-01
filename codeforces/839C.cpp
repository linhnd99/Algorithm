#include <bits/stdc++.h>

using namespace std;

vector<int> a[100001],leaf;
int n;
int level[100001];
bool kt[100001] = {};
double BFS[100001];

void bfs(int u)
{
    queue <int> q;
    q.push(u);
    kt[u]=true;
    while (!q.empty())
    {
        u=q.front();
        q.pop();
        if (u!=1 && a[u].size()==1)
        {
            leaf.push_back(u);
            continue;
        }
        for (int i=0;i<a[u].size();i++)
            if (kt[a[u][i]] == false)
            {
                level[a[u][i]] = level[u]+1;
                if (u==1)
                    BFS[a[u][i]] = BFS[u] / (a[u].size());
                else
                    BFS[a[u][i]] = BFS[u] / (a[u].size()-1);
                kt[a[u][i]]=true;
                q.push(a[u][i]);
            }
    }
}

int main()
{
    //freopen("F.INP","r",stdin);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    if (n==1)
    {
        cout << 0 << endl;
        return 0;
    }
    else if (n==2)
    {
        cout << 1;
        return 0;
    }

    level[1]=0;
    BFS[1]=100000;
    bfs(1);

    double res = 0;
    for (int i=0;i<leaf.size();i++)
    {
        res += BFS[leaf[i]]*level[leaf[i]] / 100000.0;
    }
    cout << setprecision(9) << res;
    return 0;
}
