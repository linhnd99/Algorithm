#include <bits/stdc++.h>

using namespace std;

long long f[1001];
vector<long long> a;
long long m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> m;
    f[0]=1;
    int n=0;
    for (int i=1;i<=17;i++)
    {
        f[i]=f[i-1]*3;
        n++;
    }
    for (int i=n;i>=0;i--)
    {
        if (m-f[i]>=0)
        {
            a.push_back(f[i]);
            m-=f[i];
        }
        if (m-f[i]>=0)
        {
            a.push_back(f[i]);
            m-=f[i];
        }
    }
    sort(a.begin(),a.end());
    vector<long long> left, right;
    map<long long, long long> dem;
    vector<long long> b,c;
    b.push_back(a[0]);
    c.push_back(1);
    dem[a[0]]++;
    for (int i=1;i<a.size();i++)
    {
        if (a[i]==b[b.size()-1])
        {
            c[c.size()-1]++;
        }
        else
        {
            b.push_back(a[i]);
            c.push_back(1);
        }
        dem[a[i]]++;
    }
//    for (int i=0;i<b.size();i++)
//    {
//        if (c[i]==2)
//        {
//            left.push(b[i]);
//            c[i+1]++;
//            c[i]=0;
//        }
//    }

    for (map<long long, long long> :: iterator i=dem.begin();i!=dem.end();i++)
    {
        //cout << i->first<< " "<< i->second<< endl;
        if (i->second == 2)
        {
            left.push_back(i->first);
            dem[i->first]=0;
            dem[i->first*3]++;
        }
        else if (i->second == 3)
        {
            dem[i->first*3]++;
            dem[i->first]=0;
        }
        else if (i->second == 1)
        {
            right.push_back(i->first);
            dem[i->first]=0;
        }
    }
    cout << left.size() << " ";
    for (vector<long long> :: iterator i=left.begin();i!=left.end();i++)
        cout << *i<< " ";
    cout << endl;
    cout << right.size() << " ";
    for (vector<long long> :: iterator i=right.begin();i!=right.end();i++)
        cout << *i<< " ";
    return 0;
}
