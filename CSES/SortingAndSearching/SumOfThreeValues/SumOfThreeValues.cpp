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
int n, t;

int main()
{
    cin >> n >> t;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i].f;
        v[i].s=i+1;
    }
    sort(v.begin(), v.end());

    bool possible=false;
    for (int i=1; i<n-1; i++)
    {
        int l=0, r=n-1;
        while (l!=r)
        {
            if (l==i)
            {
                l++;
                continue;
            }
            if (r==i)
            {
                r--;
                continue;
            }
            if (v[i].f+v[l].f+v[r].f>t)
            {
                r--;
            }
            else if (v[i].f+v[l].f+v[r].f<t)
            {
                l++;
            }
            else if (i!=l && i!=r && l!=r)
            {
                cout << v[i].s << " " << v[l].s << " " << v[r].s << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}

/*
4 8
2 7 5 1
*/