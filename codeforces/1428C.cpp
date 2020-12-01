#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("F.INP","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<int> st;
        for (int i=0;i<s.length();i++)
        {
            if (st.empty()) st.push(s[i]);
            else
            {
                if (s[i]=='B')
                {
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        cout << st.size() << endl;
    }
}
