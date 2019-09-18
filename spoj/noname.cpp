#include <bits/stdc++.h>

using namespace std;

bool isTwoSameSequences(std::vector<int> arr)
{
    long long f[1001];
    f[1]=arr[0];
    int n=arr.size();
    map<long long,bool> check;
    for (int i=1;i<arr.size();i++)
    {
        f[i+1]=f[i]+arr[i];
    }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            check[f[j]-f[i]]=true;
    if (f[n]%2!=0) return false;
    for (map<long long,bool> :: iterator i = check.begin();i!=check.end();i++)
    {
        cout << i->first << " " << i->second << endl;
    }
    cout << endl;
    for (int i=1;i<=n;i++)
    {
        //cout << f[i]<< " " << f[n]-f[i]<<endl;
        if (check[f[i]] && check[f[n]-f[i]]) return true;
    }
    return false;
}

int main()
{
    vector <int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(5);
    a.push_back(-8);
    cout << isTwoSameSequences(a) << endl;
    return 0;
}




int numberSteps(int n, std::vector<int> arr, int m)
{
    map<int,bool> dup;
    for (int i=0;i<arr.size();i++)
        dup[arr[i]]=true;
    arr.clear();
    for (map<int,bool> :: iterator i=dup.begin();i!=dup.end();i++)
        arr.push_back(i->first);
    queue<int> q;
    dup.clear();
    int s=n;
    q.push(s);
    map<int,int> f;
    f[s]=0;
    while (!q.empty() || f[m]!=0)
    {
        int x = q.front();q.pop();
        for (int i=0;i<arr.size();i++)
        {
            if (f[x+arr[i]]==0)
            {
                f[x+arr[i]]=f[x]+1;
                q.push(x+arr[i]);
            }
            if (f[x*arr[i]]==0)
            {
                f[x*arr[i]]=f[x]+1;
                q.push(x*arr[i]);
            }
        }
    }
    return ((f[m]==0)?(-1):f[m]);
}
