#include <bits/stdc++.h>

using namespace std;

string s,t;
int tt;

bool check(string a, string b)
{
    if (a.find(b) != string::npos) return true;
    return false;
}

string res (string s, string t)
{
    if (s>t) swap(s,t);
    map<string,bool> dic;
    string temp = s;
    for (int i=1;i<=100;i++)
    {
        dic[temp] = true;
        temp = temp+s;
    }
    temp=t;
    for (int i=1;i<=100;i++)
    {
        if (dic[temp]==true)
            return temp;
        temp = temp+t;
    }
    return "";
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> tt;
    while (tt--)
    {
        cin >> s;
        cin >> t;
        string r = res(s,t);
        if (r=="")
            cout << -1<< endl;
        else cout << r << endl;
    }
    return 0;
}
