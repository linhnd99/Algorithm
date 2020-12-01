#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> a,b;

long long P(long long x, long long n)
{
    long long s=1;
    for (long long i=x+1;i<=n;i++)
        s*=i;
    return s;
}
long long C(long long x, long long n)
{
    long long s=1;
    for (long long i=1;i<=x;i++)
        s*=(n-i+1)*i;
    return s;
}
long long gt (long long x)
{
    long long s=1;
    for (int i=2;i<=x;i++)
        s*=i;
    return s;
}

long long f(long long a, long long b)
{
    long long s=1;
    for (long long i=a+1;i<=a+b;i++)
        s=s*i/(i-a);
    return s;
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s1,s2;
    cin >> s1;
    cin >> s2;
    for (int i=0;i<s1.size();i++)
        if (s1[i]=='+') a.first ++;
        else a.second++;
    for (int i=0;i<s2.size();i++)
        if (s2[i]=='+') b.first ++;
        else if (s2[i]=='-') b.second++;
    int temp = s2.length() - b.first-b.second;
    if (temp == 0)
    {
        if (a.first==b.first) cout << 1;
        else cout <<0;
        return 0;
    }
    pair<long long,long long> c = make_pair(a.first-b.first, a.second-b.second);
    if (c.first < 0 || c.second < 0)
    {
        cout << 0;
        return 0;
    }
    //cout << f(c.first,c.second)<< endl;
    cout << setprecision(9) << f(c.first,c.second)/pow(2.0,c.first+c.second);
    return 0;
}
