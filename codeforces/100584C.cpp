#include <bits/stdc++.h>

using namespace std;

long long n,m;
string s;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s;

    long long cur=0,mi=0,ma=0;
    vector<long long> res;
    for (int i=0;i<s.length();i++)
    {
        res.push_back(cur);
        if (s[i]=='=') continue;
        if (s[i]=='>') cur--;
        else cur++;
        mi=min(mi,cur);
        ma=max(ma,cur);
    }
    res.push_back(cur);
    if (ma-mi<=m)
    {
        for (int i=0;i<res.size();i++)
            cout << res[i]-mi << " ";
    }
    else
    {
        for (int i=1;i<=n;i++)
            cout <<-1 << " ";
    }
    return 0;
}
