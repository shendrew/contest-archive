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

int n;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i].f.f >> v[i].f.s;
        v[i].s=i;
    }
    sort(v.begin(), v.end());

    set<pair<int, int>> room;
    int add=0;
    vector<int> ans(n);
    for (int i=0; i<n; i++)
    {
        if (room.lower_bound({v[i].f.f, 0})==room.begin())
        {
            add++;
            room.insert({v[i].f.s, add});
            ans[v[i].s]=add;
        }
        else
        {
            auto replace=room.lower_bound({v[i].f.f, 0});
            replace--;
            room.erase(replace);
            room.insert({v[i].f.s, (*replace).s});
            ans[v[i].s]=(*replace).s;
        }
    }

    cout << add << endl;
    for (auto &i: ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
3
1 2
2 4
4 4
*/