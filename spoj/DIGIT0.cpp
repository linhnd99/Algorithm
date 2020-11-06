#include <bits/stdc++.h>

using namespace std;

map<char, int> dic;

pair<int,int> optimize(int n)
{
    pair<int,int> res;
    for (int i=2;i<=n;i++)
    {
        int x=i;
        while (x%2==0 && x>0)
        {
            x/=2;
            res.first++;
        }
        while (x%5==0 && x>0)
        {
            x/=5;
            res.second++;
        }
    }
    return res;
}

pair<int,int> subtract (pair<int,int> a, pair<int,int> b)
{
    return make_pair(a.first-b.first, a.second-b.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string s;
    cin >> s;
    for(int i=0;i<s.length();i++)
    {
        dic[s[i]]++;
    }
    pair<int,int> res = optimize(s.length());
    for (map<char,int> :: iterator one = dic.begin(); one != dic.end(); one++)
    {
        res = subtract(res,optimize(one->second));
    }
    cout << max(0,min(res.first,res.second));
    return 0;
}
