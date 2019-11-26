#include <bits/stdc++.h>

using namespace std;

bool res (long long x, long long y)
{
    if (x>y) return true;
    if (x==y) return true;
    if (x==1) return false;
    if (x==2 || x==3)
        if (y<=3) return true;
        else return false;
    return true;
//    while (x<y && x%2==0)
//    {
//        x/=2*3;
//    }
//    if (x>=y) return true;
//    else return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        long long x,y;
        cin >> x >> y;
        cout << (res(x,y)?"YES":"NO") <<endl;
    }
    return 0;
}
