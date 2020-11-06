#include <bits/stdc++.h>

using namespace std;

string a,b;
int f[1000001];

void preKMP()
{
    a=" "+a;
    b=" "+b;
    f[1]=0;
    int k=0;
    for (int i=1;i<b.length();i++)
    {
        while (k>0 && a[k+1] != b[i])
        {
            k=f[k];
            cout << "**" << k << endl;
        }
        if (a[k+1] == b[i])
            k++;
        f[i]=k;
        cout << i << " " << k << endl;
    }
    for (int i=1;i<a.length();i++)
        cout << f[i]<< " ";
    cout <<endl;
}

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> a >> b;

    preKMP();

    return 0;


    int i=0,j=0;
    while (i<a.length())
    {
        int k=f[i];
        while (a[i]==b[j])
        {
            f[i]=j+1;
            i++,j++;
            if (i>=a.length() || j>=b.length()) break;
        }
        i++;
        f[i]=0;
        j=0;
    }
    j=a.length() - f[a.length()-1]-1;
    //cout << f[a.length()-1]<< "::"<<endl;
    for (int i=0;i<=j;i++)
        cout << a[i];
    cout <<b;
    return 0;
}
