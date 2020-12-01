#include <bits/stdc++.h>

using namespace std;

string a,b;
map<char,int> aa,bb;
int n,k;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        aa.clear();bb.clear();
        cin >> n >> k;
        cin >> a;
        cin >> b;
        for (int i=0;i<n;i++)
            aa[a[i]]++;
        for (int i=0;i<n;i++)
            bb[b[i]]++;
//        for (char i='a';i<='z';i++)
//        {
//            int dec = min(aa[i],bb[i]);
//            aa[i]-=dec;
//            bb[i]-=dec;
//        }

        a="";
        b="";
        for (char i='a';i<='z';i++)
        {
            if (aa[i]!=0) a.push_back(i);
            if (bb[i]!=0) b.push_back(i);
        }
        int first=0,second=0;
        bool res = true;
        while (first<a.length() && second<b.length())
        {
            //a_first -> b_second
            if (aa[a[first]] <= bb[b[second]])
            {
                if (a[first]<=b[second])
                {
                    int temp = aa[a[first]] / k;
                    aa[a[first]]%=k;
                    bb[b[second]]-=temp*k;
                    if (aa[a[first]] %k != 0)
                    {
                        res = false;
                        break;
                    }
                    first++;
                    if (bb[b[second]] % k !=0)
                    {
                        res = false;
                        break;
                    }
                }
                else
                {
                    res = false;
                    break;
                }
            }
            else
            {
                if (a[first]<b[second])
                {
                    int temp = bb[b[second]] / k;
                    bb[b[second]]%=k;
                    aa[a[first]]-=temp*k;
                    if (aa[a[first]] %k != 0)
                    {
                        res = false;
                        break;
                    }
                    if (bb[b[second]] % k !=0)
                    {
                        res = false;
                        break;
                    }
                    second++;
                }
                else
                {
                    res = false;
                    break;
                }
            }
        }
        cout << (res?"Yes":"No") <<endl;
    }
    return 0;
}
