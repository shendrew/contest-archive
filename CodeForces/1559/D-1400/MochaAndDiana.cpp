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
#include <functional>
using namespace std;

#define f first
#define s second
#define ll long long

int n, m1, m2;
int group[10004][2];

int root(int node, int g)
{
    if (group[node][g]==node)
    {
        return node;
    }
    return group[node][g]=root(group[node][g], g);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m1 >> m2;
    for (int i=0; i<=n; i++)
    {
        group[i][0]=i;
        group[i][1]=i;
    }
    for (int i=0; i<m1; i++)
    {
        int a, b;
        cin >> a >> b;
        group[root(a, 0)][0]=root(b, 0);
    }
    for (int i=0; i<m2; i++)
    {
        int a, b;
        cin >> a >> b;
        group[root(a, 1)][1]=root(b, 1);
    }

    vector<pair<int, int>> ans;
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            int ri0=root(i, 0), rj0=root(j, 0), ri1=root(i, 1), rj1=root(j, 1);
            if (ri0 != rj0 && ri1 != rj1)
            {
                group[ri0][0]=rj0;
                group[ri1][1]=rj1;
                ans.push_back({i, j});
            }
        }
    }

    cout << ans.size() << endl;
    for (auto &i: ans)
    {
        cout << i.f << " " << i.s << endl;
    }

    return 0;
}

/*
8 1 2
1 7
2 6
1 5
*/