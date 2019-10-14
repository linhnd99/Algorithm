#include <bits/stdc++.h>
#define ll long long
using namespace std;
void findTriangle(ll a[], ll n)
{
    ll b[n + 2];
    for (int i = 0; i < n; i++)
        b[i] = a[i] * a[i];
    sort(a, a + n);
    sort(b, b + n);
    ll x=0,y=0,z=0;
    for (int i=0; i<n; i++)
    {
        ll p = i+1;
        ll q = i+1;
        for (int j=i+1; j<n; j++)
        {
            while (p<n-1 && b[i]+b[j]>=b[p+1])
                p++;
            q = max(q, p);
            while (q<n-1 && a[i]+a[j]>a[q+1])
                q++;
            if (b[i]+b[j]==b[p])
            {
                x += max(p - j - 1, 0LL);
                y++;
                z += q - p;
            }
            else
            {
                x += max(p - j, 0LL);
                z += q - p;
            }
        }
    }
    cout<<x<<" "<<y<<" "<<z;
}
int main()
{
    ll n;
    cin>>n;
    ll arr[100005] ;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    findTriangle(arr, n);
    return 0;
}
