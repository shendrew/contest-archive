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
using namespace std;

#define f first
#define s second
#define ll long long
int n, x;

int main()
{
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i].f;
        v[i].s=i+1;
    }
    sort(v.begin(), v.end());

    int l=0, r=n-1;
    while (l!=r)
    {
        if (v[l].f+v[r].f<x)
        {
            l++;
        }
        else if (v[l].f+v[r].f>x)
        {
            r--;
        }
        else
        {
            break;
        }
    }
    if (l==r)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << v[l].s << " " << v[r].s << endl;
    }

    return 0;
}

/*
4 8
2 7 5 1
*/