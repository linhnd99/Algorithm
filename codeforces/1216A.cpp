#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int d=0;

void fn()
{
    for (int i=0;i<n-1;i+=2)
    {
        string a="ab";
        string b="ba";
        int da = (a[0]!=s[i]) + (a[1]!=s[i+1]);
        int db = (b[0]!=s[i]) + (b[1]!=s[i+1]);
        if (da<db)
        {
            s[i]=a[0];
            s[i+1]=a[1];
            d+=da;
        }
        else
        {
            s[i]=b[0];
            s[i+1]=b[1];
            d+=db;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    cin >> s;
    fn();
    cout << d<<endl<<s;
    return 0;
}
