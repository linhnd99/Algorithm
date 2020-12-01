#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int index=0,a=0,b=0,c=0;
        while (index < s.length())
        {
            if (s[index] == 'T' && s[index+1]=='J')
            {
                index+=2;
                a++;
            }
            else if (s[index] == 's' && s[index+1]=='i')
            {
                index+=2;
                b++;
            }
            else
            {
                index+=3;
                c++;
            }
        }
        cout << a << " " << b << " " <<c <<endl;
    }
    return 0;
}
