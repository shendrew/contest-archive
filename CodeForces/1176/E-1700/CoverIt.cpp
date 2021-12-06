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

int t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n+1);
        for (int i=0; i<m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int cnt=0;
        vector<int> vis(n+1);
        
        function<void (int, int)> dfs;
        dfs = [&](int node, int color)
        {
            vis[node]=color;
            if (color==2)
            {
                cnt++;
            }
            for (auto &i: graph[node])
            {
                if (!vis[i])
                {
                    dfs(i, color^3);
                }
            }
        };

        dfs(1, 1);
        if (cnt<=n/2)
        {
            cout << cnt << endl;
            for (int i=1; i<=n; i++)
            {
                if (vis[i]==2)
                {
                    cout << i << " ";
                }
            }
        }
        else
        {
            cout << n-cnt << endl;
            for (int i=1; i<=n; i++)
            {
                if (vis[i]==1)
                {
                    cout << i << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}

/*
2
4 6
1 2
1 3
1 4
2 3
2 4
3 4
6 8
2 5
5 4
4 3
4 1
1 3
2 3
2 6
5 6
*/