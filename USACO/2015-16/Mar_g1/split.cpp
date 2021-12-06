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

ifstream fin("split.in");
ofstream fout("split.out");

#define f first
#define s second
#define ll long long
int n;
long long ans, total;
vector<pair<long long, long long>> xy, yx;

void solve(vector<pair<long long, long long>> v)
{
    vector<long long> prefix, suffix;
    long long x1=v[0].f, x2=v[0].f, y1=v[0].s, y2=v[0].s, i=0;
    while (i<n)
    {
        int j=i;
        x2=v[i].f;
        while (j<n && v[j].f==v[i].f)
        {
            y1=min(y1, v[j].s);
            y2=max(y2, v[j].s);
            j++;
        }
        prefix.push_back((x2-x1)*(y2-y1));
        i=j;
    }
    x1=v[n-1].f, x2=v[n-1].f, y1=v[n-1].s, y2=v[n-1].s, i=n-1;
    while (i>=0)
    {
        int j=i;
        x2=v[i].f;
        while (j>=0 && v[j].f==v[i].f)
        {
            y1=min(y1, v[j].s);
            y2=max(y2, v[j].s);
            j--;
        }
        suffix.push_back((x1-x2)*(y2-y1));
        i=j;
    }
    reverse(suffix.begin(), suffix.end());

    for (int item=0; item<prefix.size()-1; item++)
    {
        ans=max(ans, total-(prefix[item]+suffix[item+1]));
    }
}

int main()
{
    fin >> n;
    xy.resize(n), yx.resize(n);
    long long x1=1e9+1, x2=0, y1=1e9+1, y2=0;
    for (int i=0; i<n; i++)
    {
        fin >> xy[i].f >> xy[i].s;
        yx[i].f=xy[i].s, yx[i].s=xy[i].f;
        x1=min(x1, xy[i].f), x2=max(x2, xy[i].f);
        y1=min(y1, xy[i].s), y2=max(y2, xy[i].s);
    }
    total=(x2-x1)*(y2-y1);
    sort(xy.begin(), xy.end()), sort(yx.begin(), yx.end());

    solve(xy);
    solve(yx);

    fout << ans << endl;

    return 0;
}