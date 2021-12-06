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

int x, n;

struct cmp
{
    bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) const
    {
        if (p1.s - p1.f == p2.s - p2.f)
        {
            return p1.f < p2.f;
        }
        else
        {
            return p1.s - p1.f > p2.s - p2.f;
        }
    }
};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> x >> n;
    set<int> lights={0, x};
    set<pair<int, int>, cmp> segments;
    segments.insert({0, x});
    for (int i=0; i<n; i++)
    {
        int p;
        cin >> p;
        if (p!=0 && p!=x)
        {
            lights.insert(p);
            auto lower=lights.lower_bound(p), upper=lights.upper_bound(p);
            lower--;
            segments.erase({*lower, *upper});
            segments.insert({*lower, p});
            segments.insert({p, *upper});
        }
        cout << (*segments.begin()).s-(*segments.begin()).f << " ";
    }
    cout << endl;

    return 0;
}

/*
8 3
3 6 2
*/