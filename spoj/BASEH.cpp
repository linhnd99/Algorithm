#include <bits/stdc++.h>

using namespace std;

int K,H;

string bin(long long x)
{
    string res = "";
    while (x>0)
    {
        int du = x%2;
        x/=2;
        res = res + (char)((int)('0')+du);
    }
    string res2="";
    for (int i=res.size()-1;i>=0;i--)
        res2=res2+res[i];
    return res2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> K >> H;
    cout << bin(K)<<endl;
    return 0;
}
