#include <bits/stdc++.h>

using namespace std;

bool isOK(string s, int l, int r)
{
    string b="";
    for (int i=0;i<l-1;i++)
        if (s[i]==s[l-1]) return true;
    for (int i=r;i<s.length();i++)
        if (s[r-1] == s[i]) return true;
    return false;
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n,q;
        string s;
        cin >> n >> q;
        cin >> s;
        for(int i=1;i<=q;i++)
        {
            int l,r;
            cin >> l >> r;
            cout << (isOK(s,l,r)?"YES":"NO")<<endl;
        }
    }
    return 0;
}
