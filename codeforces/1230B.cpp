#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    if (n==1)
    {
        if (k==0) cout << s;
        else cout << 0;
        return 0;
    }
    if (k==0)
    {
        cout << s;
        return 0;
    }
    int d=0;
    for (int i=0;i<n;i++)
    {
        if (i==0)
            if (s[i]=='1') cout << s[i];
            else
            {
                cout << 1;
                d++;
            }
        else if (s[i]!='0' && d<k)
        {
            d++;
            cout <<'0';
        }
        else cout <<s[i];
    }
    return 0;
}
