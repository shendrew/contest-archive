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

int n, t;
long long sum[2005][2005], area[2005][2005];
long long len[2005], wid[2005];
long long ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    vector<pair<int, int>> p1(n), p2(n);
    vector<int> tint(n);
    set<int> x, y;
    for (int i=0; i<n; i++)
    {
        cin >> p1[i].f >> p1[i].s >> p2[i].f >> p2[i].s >> tint[i];
        x.insert(p1[i].f), x.insert(p2[i].f);
        y.insert(p1[i].s), y.insert(p2[i].s);
    }
    x.insert(-1), y.insert(-1);

    map<int, int> mx, my;

    int xi=0;
    for (auto i=next(x.begin()); i!=x.end(); i++)
    {
        wid[xi]=*i-*prev(i);
        xi++;
        mx[*i]=xi;
    }
    int yi=0;
    for (auto i=next(y.begin()); i!=y.end(); i++)
    {
        len[yi]=*i-*prev(i);
        yi++;
        my[*i]=yi;
    }

    for (int i=1; i<y.size(); i++)
    {
        for (int j=1; j<x.size(); j++)
        {
            area[i][j]=len[i]*wid[j];
        }
    }

    for (int i=0; i<n; i++)
    {
        sum[my[p1[i].s]][mx[p1[i].f]]+=tint[i];
        sum[my[p2[i].s]][mx[p1[i].f]]-=tint[i];
        sum[my[p1[i].s]][mx[p2[i].f]]-=tint[i];
        sum[my[p2[i].s]][mx[p2[i].f]]+=tint[i];
    }

    for (int i=1; i<y.size(); i++)
    {
        for (int j=1; j<x.size(); j++)
        {
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            if (sum[i][j]>=t)
            {
                ans+=area[i][j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}

/*
4
3
11 11 20 15 1
13 8 14 17 2
17 8 18 17 1
12 12 19 13 1
*/