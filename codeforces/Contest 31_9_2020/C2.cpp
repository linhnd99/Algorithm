#include <bits/stdc++.h>

#define MAX 2000000001

using namespace std;

long long n,s,d;
pair<long long, long long> a[1000001];
long long ma;

bool compare(pair<long long, long long> x, pair<long long,long long> y) {
    return (x.first > y.first);
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

        bool check = false;
        long long res=0;

        for (int i=1;i<=n;i++) {
            ma = max(ma,a[i].first-a[i].second+s);
            if (a[i].second <= s) {
                res = a[i].first;
                check = true;
                break;
            }
        }


        if (check == true) {
            cout << "Case #"<<testcase<<": "<<res<<endl;
        }
        else {
            cout << "Case #"<<testcase<<": "<<ma<<endl;
        }
    }
    return 0;
}
