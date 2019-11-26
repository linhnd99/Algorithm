#include <bits/stdc++.h>

using namespace std;

bool isMatch(string a, string b)
{
    int j=0;
    for (int i=0;i<a.length();i++)
    {
        if (a[i]==b[j]) j++;
        if (j>=b.length()) return true;
    }
    if (j>=b.length()) return true;
    return false;
}

string convert(int x)
{
    string res ="";
    while (x>0)
    {
        int du = x%10;
        x/=10;
        char cc = ('0'+du);
        res = cc+res;
    }
    if (res=="") return "0";
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    for (int i=0;i<=125;i++)
    {
        string eight = convert(i*8);
        if (isMatch(s,eight))
        {
            cout <<"YES"<<endl<<eight;
            return 0;
        }
    }
    cout <<"NO";
    return 0;
}
