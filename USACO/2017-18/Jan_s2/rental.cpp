#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

ifstream fin("rental.in");
ofstream fout("rental.out");

#define f first
#define s second
int n, m, r;
long long ans;
int a[1000000];
long long cow[1000000], rent[1000000];
pair<int,int> milk[1000000];

int main()
{
    fin >> n >> m >> r;
    for (int i=0; i<n; i++)
    {
        fin >> a[i];
    }
    for (int i=0; i<m; i++)
    {
        fin >> milk[i].s >> milk[i].f;
    }
    for (int i=0; i<r; i++)
    {
        fin >> rent[i];
    }
    sort(a, a+n, greater<int>());
    sort(milk, milk+m, greater<pair<int,int>>());
    sort(rent, rent+max(n, r));

    int ci=0, mi=0;
    while (mi<m && ci<n)
    {
        int order=min(a[ci], milk[mi].s);
        cow[ci]+=milk[mi].f*order;
        milk[mi].s-=order;
        a[ci]-=order;
        if (!milk[mi].s)
        {
            mi++;
        }
        if (!a[ci])
        {
            ci++;
        }
    }

    for (int i=0; i<n; i++)
    {
        ans+=max(cow[i], rent[i+max(0, r-n)]);
    }

    fout << ans << endl;
    cout << ans << endl;

    return 0;
}