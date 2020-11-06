#include <bits/stdc++.h>

using namespace std;

void build(int x, int low, int high)
{
    l[x]=low;
    h[x]=high;
    if (low==high)
    {
        return ;
    }
    build(2*x,low,(low+high)/2);
    build(2*x+1,(low+high)/2+1,high);
    tree[x]=0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    build(1,1,n);
    for (int i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
    }
}
