#include <bits/stdc++.h>

#define MAX 2000000001

using namespace std;

long long n,s,d;
pair<long long, long long> a[1000001];
long long ma;

bool compare(pair<long long, long long> x, pair<long long,long long> y) {
    return (x.first - x.second > y.first - y.second);
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> d;
    for (int testcase=1;testcase<=d;testcase++)
    {
        ma=-MAX;
        cin >> n >> s;
        long long ss=s;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i].first >> a[i].second;
        }

        sort(a+1,a+1+n,compare);

        long long res = 0;
        int temp=0;
        for (int i=1;i<=n;i++)
        {
            if (s>=a[i].second) {
                res+=a[i].first-a[i].second;
                ma=max(ma,res);
                temp++;
            }
            else if (a[i].first-a[i].second+s>0) {
                res+=a[i].first-a[i].second+s;
                s=max(s-a[i].first,0LL);
                ma=max(ma,res);
                temp++;
            }

            //cout << i << " " << res << " " << s << " " << ma << endl;
        }
        if (temp==0) {
            cout << "Case #"<<testcase<<": "<<ss+a[1].first-a[1].second<<endl;
        }
        else {
            cout << "Case #"<<testcase<<": "<<ma<<endl;
        }
    }
    return 0;
}
