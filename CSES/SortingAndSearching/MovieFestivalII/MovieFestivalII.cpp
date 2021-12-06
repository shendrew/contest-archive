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

int n, k, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i].s >> v[i].f;
    }
    sort(v.begin(), v.end());

    multiset<pair<int, int>> member;
    member.insert(v[0]);
    ans++;
    for (int i=1; i<n; i++)
    {
        auto cur=member.upper_bound({v[i].s, 1e9+1});
        if (cur!=member.begin())
        {
            member.erase(prev(cur));
            member.insert(v[i]);
            ans++;
        }
        else if (member.size()<k)
        {
            member.insert(v[i]);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
5 2
1 5
8 10
3 6
2 5
6 9
*/