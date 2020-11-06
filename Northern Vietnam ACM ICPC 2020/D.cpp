#include <bits/stdc++.h>

using namespace std;

long long n;

long long add (long long a)
{
    long long aa = a,b=0;
    while (a>0)
    {
        b=b*10+(a%10);
        a/=10;
    }
    return aa+b;
}

long long get (long long n)
{
	if (n%7==0) return n;
    int index = 0;
    while (index<=1000)
    {
        index++;
        n=add(n);
        if (n%7==0) return n;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

	int t;
	cin >> t;
    while (t--)
    {
    	cin >> n;
        cout << get(n)<< '\n';
    }
    return 0;
}
