#include <bits/stdc++.h>

using namespace std;

const int N = 10000000;
int lp[N+1];
vector<int> pr;

int m,n;

int binarySearch(int x, int l, int r)
{
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (pr[mid] == x) return mid;
        if (x<pr[mid]) r=mid-1;
        else l=mid+1;
    }
    return r;
}

bool isBeauty (int n)
{
    int s=0;
    while (n>0)
    {
        s=s+n%10;
        n/=10;
    }
    return s%10==0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);



    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }


    cin >> m >> n;
    int index = binarySearch(m,0,pr.size()-1);
    int c=1;
    int res=0;
    while (c<=n)
    {
        while (pr[index] < m) index++;
        if (isBeauty(pr[index]))
            res++;
        c++;
        index++;
    }

    cout << res<<endl;
    return 0;
}
