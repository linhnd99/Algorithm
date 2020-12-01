#include <bits/stdc++.h>

using namespace std;

void SinhNhiPhan()
{
    int n;
    int p[1000];
    cout << "Do dai: ";
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        p[i]=0;
        cout << p[i];
    }
    cout<<endl;

    while (true) {
        bool isOver=true;
        for (int i=n;i>=1;i--)
            if (p[i]==0)
            {
                p[i]=1;
                isOver=false;
                break;
            }
            else p[i]=0;
        if (isOver) break;
        for (int i=1;i<=n;i++)
            cout << p[i];
        cout << endl;
    }
}

//------------HOAN VI-----------------------
bool kt[1000];
int pp[100],a[100];
void backtrack(int i, int n)
{
    for (int j=1;j<=n;j++)
        if (kt[j]==false)
        {
            pp[i]=a[j];
            kt[j]=true;
            if (i<n)
            {
                backtrack(i+1,n);
            }
            else
            {
                for (int jjj=1;jjj<=n;jjj++)
                    cout << pp[jjj]<< " ";
                cout << endl;
            }
            kt[j]=false;
        }
}
void HoanVi()
{
    int n,k;
    cout << "n= ";cin >> n;
    for (int i=1;i<=n;i++)
    {
        a[i]=i;
        kt[i]=false;
        pp[i]=0;
    }
    backtrack(1,n);
}

//---------FIBONACCI------------
void fibo1()
{
    int n;
    cout << "n= ";cin >> n;
    a[1]=1;
    a[2]=1;
    for (int i=3;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
    cout <<  a[n];
}
int Fibonacci(int i)
{
    if (i==1) return 1;
    if (i==2) return 1;
    return Fibonacci(i-1) + Fibonacci(i-2);
}
void fibo2()
{
    int n;
    cout << "n= ";cin >> n;
    cout << Fibonacci(n);
}

//------------THAP HA NOI---------------
void Tower(int n , char a, char b, char c ){
    if(n==1){
        cout<<"\t"<<a<<"-------"<<c<<endl;
        return;
    }
    Tower(n-1,a,c,b);
    Tower(1,a,b,c);
    Tower(n-1,b,a,c);
}
void ThapHaNoi()
{
    char a='A', b='B', c='C';
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    Tower(n,a,b,c);
}
//-------------------MA DI TUAN---------------
void backtrackMa(int x, int y, int m, int n)
{
    cout << "{"<<x << ";"<<y << "}"<<endl;
    if (x+2 <= m && y+1<=n)
        backtrackMa(x+2,y+1,m,n);
    if (x-2 >=1 && y+1<=n)
        backtrackMa(x-2,y+1,m,n);
    if (x+2 <= m && y-1>=1)
        backtrackMa(x+2,y-1,m,n);
    if (x-2 >=1 && y-1>=1)
        backtrackMa(x-2,y-1,m,n);
    if (x+1 <= m && y+2<=n)
        backtrackMa(x+1,y+2,m,n);
    if (x-1 >=1 && y+2<=n)
        backtrackMa(x-1,y+2,m,n);
    if (x+1 <= m && y-2>=1)
        backtrackMa(x+1,y-2,m,n);
    if (x-1 >=1 && y-2>=1)
        backtrackMa(x-1,y-2,m,n);
}
void MaDiTuan()
{
    int m,n;
    cout << "m= ";cin >> m;
    cout << "n= ";cin >> n;
    backtrackMa(1,1,m,n);
}

//-------------------8 HAU-----------------------
bool Ok(int x2,int y2){
    for(int i = 1; i < x2 ;i++)
        if(a[i] == y2 || abs(i-x2) == abs(a[i] - y2) )
            return false;
    return true;
}

void Xuat(int n){
    for(int i=1;i<=n;i++)
        cout << "{"<<a[i] << ";"<<i<<"} ";
    cout <<endl;
}

void Try(int i,int n){
    for(int j = 1;j<=n;j++){
        if(Ok(i,j)){
            a[i] = j;
            if(i==n) Xuat(n);
            Try(i+1,n);
        }
    }
}
void TamHau()
{
    Try(1,8);
    return 0;
}

int main()
{
    HoanVi();
    return 0;
}
