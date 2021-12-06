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
vector<pair<int, int>> v;

bool possible(double mid)
{
    double pos=v[0].f+v[0].s*mid;
    for (int i=1; i<n; i++)
    {
        if (v[i].f<pos)
        {
            pos=min(pos, v[i].f+v[i].s*mid);
        }
        else
        {
            if (v[i].f-v[i].s*mid>pos)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    v.resize(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i].f;
    }
    for (int i=0; i<n; i++)
    {
        cin >> v[i].s;
    }
    sort(v.begin(), v.end());

    cout << fixed << setprecision(6);

    double low=0, high=1e9, mid;
    while ((ll)round(1e6*low) < (ll)round(1e6*high))
    {
        mid=(low+high)/2;
        if (possible(mid))
        {
            high=mid;
        }
        else
        {
            low=mid;
        }
    }
    cout << mid << endl;

    return 0;
}

/*
4
5 10 3 2
2 3 2 4
*/