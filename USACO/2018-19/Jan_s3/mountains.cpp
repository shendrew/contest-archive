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

ifstream fin("mountains.in");
ofstream fout("mountains.out");

#define f first
#define s second
#define ll long long
int n;

bool cmp(pair<int, int> const &a, pair<int, int> const &b)
{
    if (a.f-a.s==b.f-b.s)
    {
        return a.f+a.s>b.f+b.s;
    }
    return a.f-a.s<b.f-b.s;
}

int main()
{
    fin >> n;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++)
    {
        fin >> v[i].f >> v[i].s;
    }
    sort(v.begin(), v.end(), cmp);

    int ans=n;
    pair<int, int> cur=v[0];
    for (int i=1; i<n; i++)
    {
        if (v[i].f+v[i].s<=cur.f+cur.s)
        {
            ans--;
        }
        else
        {
            cur=v[i];
        }
    }

    fout << ans << endl;

    return 0;
}