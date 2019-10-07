#include <bits/stdc++.h>

using namespace std;

bool check(string x)
{
//    int j=0;
//    for (int i=1;i<x.length();)
//    {
//        while (x[j]==x[i])
//        {
//            j++;
//            i++;
//        }
//        if (x[j]>x[j]) return false;
//        j=0;
//        i++;
//    }
//    return true;
    string L="";
    string R=x;
    for (int i=0;i<x.length()-1;i++)
    {
        L=L+x[i];
        R=R.erase(0,1);
        if (L>=R) return false;
        //cout << L << " " << R << endl;
    }
    return true;
}

string inc(string x)
{
    for (int i=x.length()-1;i>=0;i--)
    {
        if (x[i]=='0')
        {
            x[i]='1';
            return x;
        }
        else x[i]='0';
    }
    return "";
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //cout << inc("10101");
    //cout <<"*"<<check("00111")<<endl;
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        s=inc(s);
        bool isok=false;
        while (true)
        {
            if (check(s))
            {
                isok=true;
                break;
            }
            s=inc(s);
            if (s=="") break;
            //cout << s << endl;
        }
        cout << s << endl;
    }
    return 0;
}
