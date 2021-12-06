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

int n, m;
long long ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<int> b(n), g(m);
    for (int i=0; i<n; i++)
    {
        cin >> b[i];
    }
    for (int i=0; i<m; i++)
    {
        cin >> g[i];
    }
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    if (g[0]<b[n-1])
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> v(n);
    set<pair<int, int>> boy;
    for (int i=0; i<n; i++)
    {
        boy.insert({b[i], i});
        ans+=(ll)b[i]*m;
    }

    int possible=true;
    for (int i=0; i<m; i++)
    {
        auto cur=boy.upper_bound({g[i], n});
        if (cur==boy.begin())
        {
            possible=false;
            break;
        }
        ans+=g[i]-(*prev(cur)).f;
        if ((*prev(cur)).f!=g[i])
        {
            v[(*prev(cur)).s]++;
            if (v[(*prev(cur)).s]==m-1)
            {
                boy.erase(prev(cur));
            }
        }
    }

    if (possible)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}

/*
3 2
1 2 1
3 4
*/