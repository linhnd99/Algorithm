#include <bits/stdc++.h>

using namespace std;

void tomau(int u)
{
    int i=1;
    queue <int>
    for (int vi=0;vi<a[u].size();vi++)
    {

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=m;i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(y);a[x].push_back(z);
        a[y].push_back(x);a[y].push_back(z);
        a[z].push_back(x);a[z].push_back(z);
    }
    int u_min=1;
    for (int i=2;i<=n;i++)
        if (a[u_min].size() < a[i].size()) u_min=i;

}
