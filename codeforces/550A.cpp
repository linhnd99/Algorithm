#include <bits/stdc++.h>

using namespace std;
bool kt[100001];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;

    bool over=false;
    int dab=0;
    for (int i=0;i<s.length()-1;i++)
    {
        if (s[i]=='A' && s[i+1]=='B')
        {
            over=true;
            kt[i]=true;
            kt[i+1]=true;
            dab++;
        }
    }
    if (over==false)
    {
        cout<<"NO";
        return 0;
    }
    over=false;
    for (int i=0;i<s.length()-1;i++)
    {
        int temp = kt[i]+kt[i+1];
        if (s[i]=='B' && s[i+1]=='A' && !kt[i] && !kt[i+1])
        {
            over=true;
            break;
        }
        else if (s[i]=='B' && s[i+1]=='A' && dab-temp>0)
        {
            over=true;
            break;
        }
    }
    if (over==true) cout<<"YES";
    else cout <<"NO";
    return 0;
}
