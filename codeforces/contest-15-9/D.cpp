#include <bits/stdc++.h>

using namespace std;

string s;

map<char,int> a,c;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> s;
    for (int i=0;i<s.length();i++)
        if (s[i]!='!') a[s[i]]=i;
    for (int i=0;i<s.length();i++)
        if (s[i]=='!')
        {
            int index = i+4*1000;
            //RYBG
            if ((index - a['R'])%4==0) c['R']++;
            if ((index - a['Y'])%4==0) c['Y']++;
            if ((index - a['B'])%4==0) c['B']++;
            if ((index - a['G'])%4==0) c['G']++;
        }
    cout << c['R'] << " " << c['B'] << " "<<c['Y'] << " " << c['G'];
    return 0;
}
