#include <bits/stdc++.h>

using namespace std;

long long p,q;
map<long long, long long> vp,vq;

int main()
{
    //freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> p >> q;
        if (p%q!=0)
        {
            cout << p << endl;
            continue;
        }
        long long pp=p,qq=q;
        vp.clear();vq.clear();
        int index=3;
//        while (p%2==0 && p>1)
//        {
//            vp[2]++;
//            p/=2;
//        }
//        while (p>1)
//        {
//            while (p%index==0)
//            {
//                p/=index;
//                vp[index]++;
//            }
//            index+=2;
//        }

//        while (q%2==0 && q>1)
//        {
//            vq[2]++;
//            q/=2;
//        }
//        index=3;
//        while (q>1)
//        {
//            while (q%index==0)
//            {
//                q/=index;
//                vq[index]++;
//            }
//            index+=2;
//        }

        long long res=1,temp=1;
        for (int i=2;i<=sqrt(q);i++)
            if (q%i==0)
            {
                if (p/i%q!=0)
                    res = max(res,p/i);
                if (p/(q/i)%q!=0)
                    res = max(res,p/(q/i));
            }
//        p=pp;
//        q=qq;
//        for (map<long long, long long> :: iterator i = vq.begin();i!=vq.end();i++)
//        {
//            temp=1;
//            for (int j=1;j<=i->second;j++)
//            {
//                temp=temp * i->first;
//                //cout << "%%"<<p<< " " << temp<< " " << p/temp<< endl;
//                if ((p/temp) % q != 0)
//                {
//                    res = max(res,p/temp);
//                    break;
//                }
//            }
//        }
        cout << res << endl;
    }
}
