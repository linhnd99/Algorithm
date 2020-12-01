#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> a[200001];
vector<int> leaf;
long long level[200001],par[200001],child[200001];
bool kt[200001]={};

void bfs(int u)
{
    queue <int> q;
    q.push(u);
    level[u]=1;
    kt[u]=true;
    while (!q.empty())
    {
        u=q.front();
        q.pop();
        if (a[u].size()==1 && u!=1)
            leaf.push_back(u);
        for (int i=0;i<a[u].size();i++)
        {
            if (kt[a[u][i]] == false)
            {
                level[a[u][i]] = level[u] + 1;
                par[a[u][i]] = u;
                kt[a[u][i]] = true;
                q.push(a[u][i]);
            }
        }
    }
}

void dfs(int u)
{
    kt[u]=true;
    if (a[u].size()==1 && u!=1)
    {
        leaf.push_back(u);
        child[u]=0;
        return ;
    }
    for (int i=0;i<a[u].size();i++)
    {
        if (kt[a[u][i]] == false)
        {
            level[a[u][i]] = level[u] + 1;
            par[a[u][i]] = u;
            kt[a[u][i]] = true;
            dfs(a[u][i]);
            child[u]+=child[a[u][i]];
        }
    }
    child[u] += a[u].size()-1;
}

bool Compare(pair<long long,long long> x, pair<long long,long long> y)
{
    if (x.first < y.first) return false;
    else if (x.first>y.first) return true;
    else if (x.second > y.second)
    {
        return false;
    }
    else if (x.second < y.second)
    {
        return true;
    }
    else return false;
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    level[1]=1;
    dfs(1);
    child[1]++;


    par[1]=-1;
//    for (int i=0;i<leaf.size();i++)
//    {
//        int index = leaf[i];
//        while (index>1)
//        {
//            child[par[index]]+=child[index]+1;
//            index = par[index];
//        }
//    }



    vector< long long > v;
    for (int i=1;i<=n;i++)
        v.push_back(level[i]-child[i]-1);

    sort(v.begin(),v.end(), greater<long long>());


    long long res=0;
    for (int i=0;i<k;i++)
    {
        res += v[i];
    }
    cout << res <<endl;
    return 0;
}
