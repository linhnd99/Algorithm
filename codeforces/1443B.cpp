#include <bits/stdc++.h>

using namespace std;

int a,b;
string s;

int main()
{
    //freopen("F.INP","r",stdin);
    int t,n;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cin >> s;
        string temp="";
        temp = temp+s[0];
        for (int i=1;i<s.length();i++)
            if (s[i]!=temp[temp.length()-1] || s[i]=='0') temp=temp+s[i];

        int start = 0;
        int endd = temp.length()-1;
        while (temp[start]=='0')
        {
            start++;
            if (start>=temp.length()) break;
        }
        while (temp[endd]=='0')
        {
            endd--;
            if (endd<0) break;
        }
        if (start>endd)
        {
            cout << 0 <<endl;
            continue;
        }

        int s=a;
        int pre = start;
        for (int i=start+1;i<=endd;i++)
            if (temp[i]=='1')
            {
                int cost1 = (i-pre-1)*b;
                s+=min(cost1,a);
                pre=i;
            }
        cout << s << endl;
    }
    return 0;
}

