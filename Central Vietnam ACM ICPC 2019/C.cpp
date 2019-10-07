#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--)
    {
        long long x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queue <long long> q;
        map <pair<long long,long long>, bool> kt;
        int d=0;
        q.push(x1);
        q.push(y1);
        kt[make_pair(x1,y1)]=true;
        while (!q.empty())
        {
            d++;
            if (d>10000) break;
            //cout << x1 << " " <<y1 << endl;
            x1=q.front();q.pop();
            y1=q.front();q.pop();
            if (!kt[make_pair(x1-y1,y1)])
            {
                q.push(x1-y1);
                q.push(y1);
                kt[make_pair(x1-y1,y1)]=true;
                if (x1-y1==x2 && y1==y2) break;
            }
            if (!kt[make_pair(x1+y1,y1)])
            {
                q.push(x1+y1);
                q.push(y1);
                kt[make_pair(x1+y1,y1)]=true;
                if (x1+y1==x2 && y1==y2) break;
            }
            if (!kt[make_pair(x1,y1-x1)])
            {
                q.push(x1);
                q.push(y1-x1);
                kt[make_pair(x1,y1-x1)]=true;
                if (x1==x2 && y1-x1==y2) break;
            }
            if (!kt[make_pair(x1,y1+x1)])
            {
                q.push(x1);
                q.push(y1+x1);
                kt[make_pair(x1,y1+x1)]=true;
                if (x1==x2 && y1+x1==y2) break;
            }
        }
        if (kt[make_pair(x2,y2)]==true) cout << "YES"<<endl;
        else cout << "NO" << endl;
    }
    return 0;
}
