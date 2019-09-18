#include <bits/stdc++.h>

using namespace std;

bool is(string s)
{
    int a=0,b=0;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]!='4' && s[i]!='7') return false;
        if (i<s.length()/2) a+=s[i]-'0';
        else b+=s[i]-'0';
    }

    return (a==b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;
    cout << ((is(s)==true)?"YES":"NO");
    return 0;
}
