#include <bits/stdc++.h>

using namespace std;

long long q,n,k;
string s;
vector<long long> v;
bool kt[1000002];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--)
    {
        v.clear();
        cin >> n >>k;
        cin >> s;
        //bool kt[s.length()]={};
        memset(kt,false,sizeof(kt));
        for (int i=0;i<s.length();i++)
            if (s[i]=='0')
            {
                v.push_back(i);
                kt[i]=true;
            }
        for(int i=0;i<v.size();i++)
        {
            if (v[i]-i<=k)
            {
                kt[v[i]]=false;
                k-=v[i]-i;
                v[i]=i;
                kt[i]=true;
            }
            else
            {
                kt[v[i]]=false;
                v[i]=v[i]-k;
                k=0;
                kt[v[i]]=true;
                break;
            }
        }
        for (int i=0;i<s.length();i++)
            if (kt[i]) cout <<0;
            else cout << 1;
        cout<<endl;
    }
    return 0;
}
