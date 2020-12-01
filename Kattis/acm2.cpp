#include <bits/stdc++.h>

using namespace std;

vector<long long> v;
long long n,res,p,pen,cur;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> p;
    for (int i=0;i<n;i++)
    {
        long long x;
        cin >> x;
        if (p==i)
        {
            pen = x;
            cur = x;
        }
        else v.push_back(x);
    }

    sort(v.begin(),v.end());

    if (cur>300)
    {
        cout << 0 << " " << 0;
        return 0;
    }
    res=1;
    for (auto ele : v)
    {
        if (cur+ele<=300)
        {
            cur+=ele;
            pen+=cur;
            res++;
        }
        else break;
    }
    cout << res << " " << pen<<endl;
    return 0;
}
