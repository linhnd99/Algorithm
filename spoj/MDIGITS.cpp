#include <bits/stdc++.h>

using namespace std;

long long a,b;

vector<long long> cal(int x)
{
    map<int,long long> dem;
    long long mu=1;
    long long nho=0;
    while (x>=1)
    {
        long long du = x%10;
        x/=10;
        if (mu==1)
        {
            dem[du]++;
        }
        else
        {
            dem[du]+=nho+1;
            if (x>=10)
                for (int i=du-1;i>=0;i--)
                    dem[i]+=mu;
            else
                for (int i=du-1;i>=1;i--)
                    dem[i]+=mu;
        }
        nho=du*mu+nho;
        mu=mu*10;
        cout << nho<<endl;
    }
    vector<long long> res;
    for (int i=0;i<=9;i++)
        res.push_back(dem[i]);
    return res;
}
vector<int> f(int x)
{
    vector<int> temp;
    for (int i=0;i<=9;i++) temp.push_back(0);
    if (x<=9)
    {
        temp[x]++;
        return temp;
    }
    while (x>=1)
    {
        temp[x%10]++;
        x/=10;
    }
    return temp;
}
vector<int> cong(vector<int> x, vector<int> y)
{
    vector <int> res;
    for (int i=0;i<=9;i++)
        res.push_back(x[i]+y[i]);
    return res;
}
vector <int> trau (int x)
{
    vector<int> s;
    for (int i=0;i<=9;i++) s.push_back(0);
    for (int i=0;i<=x;i++)
        s=cong(s,f(i));
    return s;
}

int main()
{
    freopen("f.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    vector <long long> c = cal(10);
    vector <int> ctrau = trau(9999);

    for (int i=0;i<=9;i++)
        cout << c[i]<< " ";cout<<endl;

    cout << "trau:"<<endl;
    for (int i=0;i<=9;i++)
        cout << ctrau[i]<< " ";cout<<endl;
    return 0;
//
//    while (true)
//    {
//        cin >> a >> b;
//        if (a==0 && b==0) return 0;
//        vector <long long> ca = cal(a-1);
//        vector <long long> cb = cal(b);
//        for (int i=0;i<=9;i++)
//            ca[i]=cb[i]-ca[i];
//        for (int i=0;i<=9;i++)
//            cout << ca[i]<< " ";
//        cout<<endl;
//    }
    return 0;
}
