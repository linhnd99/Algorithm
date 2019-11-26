#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[701][701];
bool kt[701][701]={};

int area(int i, int j)
{
    if ((i==1 && j==1) || (i==n &&j==m) || (i==1 && j==m) || (i==n && j==1)) return 3;
    if (i==1||i==n) return 5;
    if (j==1 || j==m) return 5;
    return 8;
}

pair<int,int> dem(int i, int j)
{
    int d=0;
    for (int x=-1;x<=1;x++)
        for (int y=-1;y<=1;y++)
            if ((x!=0||y!=0) && a[i][j]>=a[i+x][j+y]) d++;
    if (a[i][j]==0) return make_pair(0,area(i,j));
    else
        return make_pair(d,area(i,j));
}

void bfs(int i, int j)
{
    int c = a[i][j];
    queue <int> q;
    q.push(i);
    q.push(j);
    kt[i][j]=true;
    while (!q.empty())
    {
        i=q.front();q.pop();
        j=q.front();q.pop();
        c=a[i][j];
        for (int x=-1;x<=1;x++)
            for (int y=-1;y<=1;y++)
                if (x!=0||y!=0)
                {
                    if (a[i+x][j+y]<=c && kt[i+x][j+y]!=true && a[i+x][j+y]!=0)
                    {
                        kt[i+x][j+y]=true;
                        q.push(i+x);
                        q.push(j+y);
                    }
                }
    }
}
int main()
{
    freopen("f.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> a[i][j];
    for (int i=0;i<=n+1;i++)
    {
        a[i][0]=1000000;
        a[i][m+1]=1000000;
    }
    for (int j=0;j<=m+1;j++)
    {
        a[0][j]=1000000;
        a[n+1][j]=1000000;
    }
    vector<pair<int,int> > v;
    vector<pair<int,pair<int,int> > > vv;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            pair<int,int> t = dem(i,j);
            //cout << i << " " << j << " " <<t.first<< " " <<t.second<<endl;
            if (t.first==t.second)
            {
                v.push_back(make_pair(i,j));
                vv.push_back(make_pair(-a[i][j],make_pair(i,j)));
            }
        }
    sort(vv.begin(),vv.end());
    for (int i=0;i<v.size();i++)
    {
        v[i]=vv[i].second;
        //cout <<vv[i].first<< " "<< v[i].first<< " " <<v[i].second <<endl;
    }
    int d=0;
    for (int i=0;i<v.size();i++)
        if (kt[v[i].first][v[i].second] == false)
        {
            d++;
            bfs(v[i].first,v[i].second);
            //cout << v[i].first<< " " <<v[i].second<<"???"<<endl;
        }
    cout << d << endl;
    return 0;
}
