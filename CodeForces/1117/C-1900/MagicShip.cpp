#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

#define f first
#define s second
#define ll long long

int n;
string str;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> str;
    vector<pair<long long, long long>> prefix(n+1);
    for (int i=1; i<=n; i++)
    {
        char cur=str[i-1];
        int curX=0, curY=0;
        if (cur=='U')
            curY++;
        else if (cur=='D')
            curY--;
        else if (cur=='R')
            curX++;
        else if (cur=='L')
            curX--;
        prefix[i]={prefix[i-1].f+curX, prefix[i-1].s+curY};
    }

    long long low=0, high=2e14, mid;
    while (low<high)
    {
        mid=low+(high-low)/2;
        if (abs(x1 + prefix[n].f*(mid/n)+prefix[mid%n].f - x2) + abs(y1 + prefix[n].s*(mid/n)+prefix[mid%n].s - y2) <= mid)
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    if (high==2e14)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mid << endl;
    }

    return 0;
}

/*
0 0
4 6
3
UUU
*/  