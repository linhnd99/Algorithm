#include <bits/stdc++.h>

using namespace std;

int t;
int n;
long long a[100001],res[100001];


int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> a[i];
        stack <int> st;
        int p=1;
        a[0]=0;
        bool over=false;
        for (int i=1;i<=n;i++)
        {
            if (a[i]==a[i-1] && st.size()==0)
            {
                over=true;
                break;
            }
            if (a[i]==a[i-1])
            {
                res[i]=st.top();
                st.pop();
            }
            else
            {
                while (p<a[i])
                {
                    st.push(p);
                    p++;
                }
                res[i]=a[i];
                p++;
            }
        }
        if (over) cout <<-1 <<endl;
        else
        {
            for (int i=1;i<=n;i++) cout << res[i]<< " ";
            cout<<endl;
        }
    }
    return 0;
}
