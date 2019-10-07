#include <bits/stdc++.h>
#define maxn 123456
#define maxx 1234567
using namespace std;
bool check[maxx],check1[maxx];
multiset<int> Ms;
int a[maxn],f[maxn],Key[maxx];
int p[100];

void Prime()
{
	for(int i=2;i*i<=maxx;i++)
	{
		if(!check[i])
			for(int j=i*i;j<=maxx;j+=i)
				check[j]=true;
	}
}
int main()
{
    freopen("F.INP","r",stdin);
	Prime();
	check[1]=true;
	check[0]=true;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(!check[x])
			a[i]=1;
		else
			a[i]=-1;
	}

	for (int i=1;i<=n;i++) cout << a[i]<< " ";cout<<endl;

	f[0]=0;
    for (int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+a[i];
    }
    long long first = 0, last=1, res=0;
    long long c=0;
    while (last<=n)
    {
        if (f[last]-f[first]>=0)
        {
            c++;
            res += c;
            last++;
        }
        else first++;
        //cout << "#"<<res<<endl;
    }
    f[0]=0;
    res=0;
    int sd=0,sa=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==1)
        {
            sd++;
            res +=max((sd-sa),0);
        }
        else
        {
            sa++;
            sd++;
            res +=max((sd-sa),0);
        }
    }
    cout << res;
    return 0;
}
