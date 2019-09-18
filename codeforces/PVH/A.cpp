#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int step=0;
    //1+2->3
    if (a[1]<a[2])
    {
        step+=a[1];
        a[3]+=a[1];
        a[2]-=a[1];
        a[1]=0;
    }
    else
    {
        step += a[2];
        a[1]-=a[2];
        a[3]+=a[2];
        a[2]=0;
    }
    //2+2->4
    if(a[1]==0)
    {
        if(a[2]%2==0)
        {
            step+=a[2]/2;
        }
        else
        {
            return cout<<-1,0;
        }
    }
    else if(a[2]==0)
    {
        if((a[1]==1||a[1]==2||a[1]==5)&&a[3]==0)
        {
            return cout<<-1,0;
        }
        else if(a[3]!=0)
        {
            step+=min(a[1],a[3]);
        }
        else
        {
            if (a[1]<a[3])
            {
                step+=a[1];
                a[4]+=a[1];
                a[3]-=a[1];
                a[1]=0;
            }
            else
            {
                step+=a[3];
                a[1]-=a[3];
                a[4]+=a[3];
                a[3]=0;
            }
        }
    }
    else if(a[2]==0&&a[3]==0)
    {
        if(a[1]%2==0)
            a[2]+=a[1]/2;
    }
    else//(4-1)->2->3
    {
        if(a[2]!=0&&a[4]!=0)
            step+=min(a[2],a[4]);
    }

    //step+=a[2]/2;
    //a[2]=a[2]%2;
    //1+3->4
    cout<<step;


    return 0;
}
