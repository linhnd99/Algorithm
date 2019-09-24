#include <bits/stdc++.h>

using namespace std;

int kmpp(char t[], char s[])
{
    int next[10000];
    int j;
    j = next[0] = -1;
    int ls = strlen(s), lt = strlen(t);

    for(int i = 1; i < ls; ++i) {
        while (j >= 0 && s[j+1] != s[i]) j = next[j];
        if (s[j+1] == s[i]) ++j;
        next[i] = j;
    }

    j = -1;
    for(int i = 0; i < lt; ++i) {
        while (j >= 0 && s[j+1] != t[i]) j = next[j];
        if (s[j+1] == t[i]) ++j;

        if (j == ls - 1) { // Het xau s
            printf("%d ", i - j + 1);
            j = next[j];
        }
    }
    puts("");
}

int kmp(string a, string b)
{
    int next[10000];
    int j=next[0]=-1;
    int res=0;

    for (int i=0;i<a.length();++i)
    {
        while(j>0 && a[j+1] !=a[i]) j=next[j];
        if (a[j+1]==a[i]) j++;
        next[i]=j;
    }
    j=-1;
    for (int i=0;i<b.length();++i)
    {
        while (j>0 && a[j+1]!=b[i]) j=next[j];
        if (a[j+1]==b[i]) ++j;
        if (j==a.length()-1)
        {
            cout <<"??"<<endl;
            res = i-j+1;
            j=next[j];
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string aa="aaaa";
    string bb="aa";
    cout << kmpp("aaaa","aa")<<endl;
    cout <<kmp("aaaa","aa");
//    cin >> n >> m;
//    for (int i=1;i<=n;i++)
//    {
//        string x;
//        cin >> x;
//        s.push_back(x);
//    }
//    for (int i=1;i<=m;i++)
//    {
//        string x;
//        cin >> x;
//        queue<string> q;
//        q.push(x);
//        while (!q.empty())
//        {
//            x=q.front();x=q.pop();
//            for (int j=0;j<x.length();x++)
//                if (x[j]=='?')
//                {
//                    for (char c='a'; c<='e';c++)
//                    {
//                        x[j]=c;
//                        q.push(x);
//                    }
//                    q.push(x.substr(0,i)+x.substr(i+1,x.length()-(x+1)));
//                }
//        }
//    }



}
