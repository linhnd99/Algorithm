#include <bits/stdc++.h>

using namespace std;
int s,t,n,m;
vector<int> a[10001];
int trace[10001];


void hello()
{
    queue<int> q;
    bool kt[1001]={};
    int u=s;
    q.push(u);
    kt[u]=true;
    while (!q.empty())
    {
        u=q.front();
        q.pop();
        for (auto v : a[u])
            if (kt[v]==false)
            {
                trace[v]=u;
                kt[v]=true;
                q.push(v);
                if (v==t)
                {
                    break;
                }
            }
    }

    vector<int> path;
    map<int,bool> dic;
    map<int,int> trace2;
    u=t;
    while (u!=0)
    {
        dic[u]=true;
        path.push_back(u);
        u=trace[u];
    }
    reverse(path.begin(),path.end());

    vector<int> index (n+2,1000000000);
    for (int i=0;i<path.size();i++)
        index[path[i]]=i+1;

    for (int i=0;i<path.size()-1;i++)
    {
        queue<int> emptyy;
        swap(q,emptyy);
        u=path[i];
        for (auto v : a[u])
        {
            if (path[i+1]!=v) q.push(v);
        }
        while (!q.empty())
        {
            u=q.front();
            q.pop();
            for (auto v : a[u])
            {
                if (dic[v] == true)
                {
                    if (trace2[v]==0) trace2[v]=path[i];
                    else if (index[trace2[v]] > index[path[i]]) trace2[v]=path[i];
                }
                else
                {
                    q.push(v);
                    trace2[v]=path[i];
                }
            }
        }
    }

//    for (int i=0;i<path.size();i++)
//        cout << path[i]<< " "<<trace[path[i]]<<endl;

    int l = min((int)(path.size()-1), index[trace2[path[path.size()-1]]]);
    int res=0;
    for (int i=path.size()-2;i>=1;i--)
    {
        //cout << i<< " " << trace2[path[i]]<< " " << path[i]<< " " << l << endl;
        if (i+1 <= l)
        {
            res++;
            //cout << i+1<< ":" ;
        }
        l=min(l,index[trace2[path[i]]]);
        //cout << i<< " " << trace2[path[i]]<< " " << path[i]<< " " << l << endl;
    }
    cout << res<<endl;
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
    }

    hello();

    return 0;

}
