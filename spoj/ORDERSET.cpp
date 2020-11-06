#include <bits/stdc++.h>

using namespace std;

vector<int> heap;
int q;


int binarySearch(int x)
{
    int l=0,r=heap.size()-1;
    while(l<r)
    {
        int mid = (l+r)/2;
        if (x>heap[mid]) r=mid-1;
        else l=mid+1;
    }
    return l;
}

void INSERT(int x)
{
    if (heap.size()!=0)
    {
        int temp = binarySearch(x);
        if (temp<heap.size() && temp>=0)
        {
            if (heap[temp] == x) return ;
        }
    }
    heap.push_back(x);
    push_heap(heap.begin(),heap.end());
}


void COUNT(int x)
{
    if (x > heap.front())
        cout << heap.size()<<endl;
    else
        cout << binarySearch(x) << endl;
}

void DELETE(int x)
{
    if (x > heap.front() || x<heap[heap.size()-1]) return;
    int temp = binarySearch(x);
    if (heap[temp]==x)
    {
        heap[temp]=-1000000001;
        push_heap(heap.begin(),heap.end());
        heap.erase(heap.begin()+heap.size()-1, heap.begin()+heap.size());
        push_heap(heap.begin(),heap.end());
    }
}

void KTH(int x)
{
    if (x<0 || x>heap.size()) cout << "invalid"<<endl;
    else cout << heap[heap.size()-x] << endl;
}

int main()
{
    freopen("F.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> q;
    while (q--)
    {
        make_heap(heap.begin(),heap.end());
        string s;
        int x;

        cin >> s >> x;
        if (s[0]=='I')
            INSERT(x);
        else if (s[0]=='C')
            COUNT(x);
        else if (s[0]=='D')
            DELETE(x);
        else if (s[0]=='K')
            KTH(x);
    }
//    DELETE(-1);
//    for (int i=0;i<heap.size();i++)
//        cout << heap[i]<< " ";

    return 0;
}
