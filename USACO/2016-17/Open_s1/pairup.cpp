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

ifstream fin("pairup.in");
ofstream fout("pairup.out");

#define f first
#define s second
#define ll long long
int n, total, ans;

int main()
{
    fin >> n;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++)
    {
        fin >> v[i].s >> v[i].f;
        total+=v[i].s;
    }
    sort(v.begin(), v.end());

    int l=0, r=n-1, p=0, i=0, j=0;
    while (p<total)
    {
        ans=max(ans, v[l].f+v[r].f);
        int inc=min(v[l].s-i, v[r].s-j);
        i+=inc, j+=inc;
        if (i==v[l].s)
        {
            l++;
            i=0;
        }
        if (j==v[r].s)
        {
            r--;
            j=0;
        }
        p+=inc;
    }
    fout << ans << endl;

    return 0;
}