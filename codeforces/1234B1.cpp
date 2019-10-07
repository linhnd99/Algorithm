#include <bits/stdc++.h>

using namespace std;

int n,k,first,last;
int a[1000001],que[1000001];
map<int,bool> dup;


void push(int x)
{
    que[++last]=x;
}
int pop()
{
    return que[first++];
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    first=1;
    last=0;
    for (int i=1;i<=n;i++)
    {
//        cout << first<<"+"<<last << ": ";
//        for (int j=first;j<=last;j++) cout << que[j]<<" ";cout<<endl;
        if (dup[a[i]]==true) continue;
        dup[a[i]]=true;
        push(a[i]);
        if (last-first+1>k)
        {
            int val = pop();
            dup[val]=false;
        }
    }
    cout << last-first+1<<endl;
    for (int i=last;i>=first;i--)
        cout << que[i]<< " ";
    return 0;
}
