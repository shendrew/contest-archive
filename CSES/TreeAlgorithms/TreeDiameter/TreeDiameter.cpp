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

int n;
vector<int> adj[200005];
int vis[200005];

pair<int, int> dfs(int node, int dist) // node, dist
{
    pair<int, int> ret={node, dist};
    vis[node]=1;
    for (auto &i: adj[node])
    {
        if (!vis[i])
        {
            pair<int, int> cur=dfs(i, dist+1);
            if (cur.s>ret.s)
            {
                ret=cur;
            }
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    pair<int, int> far1=dfs(1, 0);
    memset(vis, 0, sizeof(vis));
    pair<int, int> ans=dfs(far1.f, 0);
    cout << ans.s << endl;

    return 0;
}

/*
5
1 2
1 3
3 4
3 5
*/