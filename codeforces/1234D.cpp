#include <bits/stdc++.h>

using namespace std;
bool it[30][300001];
int l[300001],h[300001],leaf[100001];
string s;
int n;

void build(int x, int low, int high)
{
    l[x]=low;
    h[x]=high;
    if (low==high)
    {
        it[s[low-1]-'a'][x]=true;
        leaf[low]=x;
        return ;
    }
    build(2*x,low,(low+high)/2);
    build(2*x+1,(low+high)/2+1,high);
    for (int i=0;i<='z'-'a'+1;i++)
        it[i][x]=(it[i][2*x] || it[i][2*x+1]);
}

void update(int pos, char ch)
{
    int x = leaf[pos];
    it[s[pos-1]-'a'][x]=false;
    while (x>1)
    {
        x/=2;
        it[s[pos-1]-'a'][x]=(it[s[pos-1]-'a'][2*x] || it[s[pos-1]-'a'][2*x+1]);
    }
    x = leaf[pos];
    s[pos-1]=ch;
    it[s[pos-1]-'a'][x]=true;
    while (x>1)
    {
        x/=2;
        it[s[pos-1]-'a'][x]=(it[s[pos-1]-'a'][2*x] || it[s[pos-1]-'a'][2*x+1]);
    }
}

bool query(int x, int low, int high, int i)
{
    //cout << x << " " << low<< " " << high<< " "<<l[x] << " " << h[x]<<" " << (low<=l[x] && h[x]<=high)<< endl;
    if (low<=l[x] && h[x]<=high) return it[i][x];
    if (high<l[x] || h[x]<low) return false;
    return (query(2*x,low,high,i) || query(2*x+1,low,high,i));
}

int cal(int l, int r)
{
    int d=0;
    for (int i=0;i<='z'-'a'+1;i++)
        if (query(1,l,r,i))
        {
            d++;
            //cout << "+ "<<(char)(i+'a')<<endl;
        }
    return d;
}

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> s;
    build(1,1,s.length());
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        //cout <<i<<":::"<<endl;
        int type;
        cin>>type;
        if (type==1)
        {
            int pos;
            char ch;
            cin >> pos >> ch;
            update(pos,ch);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << cal(l,r)<<endl;
        }

    }
    //cout <<"###"<<query(1,4,6,'a'-'a');
    return 0;
}
