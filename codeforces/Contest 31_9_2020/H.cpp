#include <bits/stdc++.h>

using namespace std;

pair<int,int> a[100],b[100];

void baoloi() {
    //find first vector with 2 points have Y highest
    int index_max1=1, index_max2=0;
    for (int index = 2; index<=c; index++)
        if (a[index].second >= a[index_max1].second) {
            index_max2 = index_max1;
            index_max1 = index;
        }

    bool check[c+1]={};
    check[index_max2] = true;
    check[index_max1] = true;

    pair<int,int> firstPoint, secondPoint, v;
    firstPoint = a[index_max1];
    secondPoint = a[index_max2];
    v.first = secondPoint.first - firstPoint.first;
    v.second = secondPoint.second - firstPoint.second;

    //find point has alpha min with vector v
    for (int i=1;i<=c;i++)
    {

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    for (int test=1;test<=t;test++) {
        cin >> c >> p;

        for (int i=1;i<=c;i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        for (int i=1;i<=p;i++) {
            cin >> b[i].first >> b[i].second;
        }


    }
}
