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

ifstream fin("helpcross.in");
ofstream fout("helpcross.out");

#define f first
#define s second
#define ll long long

int c, n, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fin >> c >> n;
    multiset<int> chick;
    vector<pair<int, int>> cow(n);
    for (int i=0; i<c; i++)
    {
        int c;
        fin >> c;
        chick.insert(c);
    }
    for (int i=0; i<n; i++)
    {
        fin >> cow[i].s >> cow[i].f;
    }
    sort(cow.begin(), cow.end());

    for (int i=0; i<n; i++)
    {
        auto cur=chick.lower_bound({cow[i].s});
        if (cur==chick.end())
        {
            continue;
        }
        if (*cur<=cow[i].f)
        {
            chick.erase(cur);
            ans++;
        }

    }

    fout << ans << endl;

    return 0;
}