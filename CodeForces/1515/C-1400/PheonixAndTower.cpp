#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

#define f first
#define s second
int t;

int main()
{
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> ans(n);
        vector<pair<int, int>> v(n);
        set<pair<int, int>> tower;
        for (int i=0; i<n; i++)
        {
            cin >> v[i].f;
            v[i].s=i;
        }
        for (int i=1; i<=m; i++)
        {
            tower.insert({0, i});
        }
        sort(v.begin(), v.end());
        for (int i=0; i<n; i++)
        {
            pair<int, int> cur=*tower.begin();
            tower.erase(cur);
            cur.f+=v[i].f;
            tower.insert(cur);
            ans[v[i].s]=cur.s;
        }

        cout << "YES" << endl;
        for (auto &i: ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
2
5 2 3
1 2 3 1 2
4 3 3
1 1 2 3
*/