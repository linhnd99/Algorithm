#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        map<char,bool> check;
        vector<int> dem;
        vector<char> c;
        cin >> s;

        c.push_back(s[0]);
        dem.push_back(1);
        for (int i=1;i<s.length();i++)
        {
            if (s[i]==c[c.size()-1]) dem[dem.size()-1]++;
            else
            {
                c.push_back(s[i]);
                dem.push_back(1);
            }
        }
        for (int i=0;i<c.size();i++)
        {
            if (dem[i]%2!=0)
            {
                check[c[i]]=true;
            }
            //cout << c[i]<< " " <<dem[i]<<endl;
        }
        for (char x ='a';x<='z';x++)
            if (check[x]) cout <<x;
        cout<<endl;
    }
    return 0;
}
