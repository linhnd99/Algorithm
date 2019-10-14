#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    set <pair<int,int> > before;
    for (int i=1;i<=n;i++)
    {
        set <pair<int,int> > :: iterator  vt = upper_bound(before.begin(),before.end(),make_pair(a[i],i));
        cout << vt->first << endl;
        before.insert(make_pair(a[i],i));
    }
    set <pair<int,int> > :: iterator  vt = lower_bound(before.begin(),before.end(),make_pair(2,5));
    cout << "!!"<<vt->first << endl;
    return 0;
}
