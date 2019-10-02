#include <bits/stdc++.h>

using namespace std;

int n;
int a[10001];

int l[10001],h[10001],it[10001];
int leaf[10001];

void build(int x, int low, int high)
{
    l[x]=low;
    h[x]=high;
    if (low==high)
    {
        it[x] = a[low];
        leaf[low]=x;
        return ;
    }
    build(2*x,low,(low+high)/2);
    build(2*x+1,(low+high)/2+1,high);
    it[x]=it[2*x]+it[2*x+1];
}

void update(int pos, int val)
{
    int x = leaf[pos];
    it[x]=val;
    while (x!=1)
    {
        x/=2;
        it[x]=it[x*2]+it[2*x+1];
    }
}

int query(int x, int low, int high)
{
    if (low<=l[x] && h[x]<=high)
    {
        return it[x];
    }
    if (h[x]<low || high<l[x]) return 0;
    return query(2*x,low,high) + query(2*x+1,low,high);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    build(1,1,n);
    update(1,100);
    cout << query(1,1,3);
    return 0;
}
