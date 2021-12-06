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
double ans;
vector<int> adj[100005];
int vis[100005];

void dfs(int node, int d, double p)
{
    if (vis[node])
    {
        return;
    }
    vis[node]=1;
    int num=0;
    for (auto &i: adj[node])
    {
        if (!vis[i])
        {
            num++;
        }
    }

    if (num==0)
    {
        ans+=p*d;
    }

    for (auto &i: adj[node])
    {
        dfs(i, d+1, p/num);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 1);

    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}

/*
4
1 2
1 3
2 4
*/