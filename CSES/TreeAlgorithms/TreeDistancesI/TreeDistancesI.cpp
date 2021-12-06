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
int vis[200005], depth[200005], ans[200005], partial[200005];
vector<int> prefix[200005], suffix[200005];
map<int, int> ind;

int dfs(int node, int dist)
{
    int ret=0;
    vis[node]=1;
    for (auto &i: adj[node])
    {
        if (!vis[i])
        {
            ret=max(ret, dfs(i, dist+1));
        }
    }
    depth[node]=ret;
    return ret+1;
}

void solve(int node, int parent)
{
    int pos=0;
    prefix[node].push_back(-1);
    for (auto &i: adj[node])
    {
        if (i!=parent)
        {
            ind[i]=pos;
            prefix[node].push_back(depth[i]);
            suffix[node].push_back(depth[i]);
            pos++;
        }
    }
    suffix[node].push_back(-1);
    for (int i=1; i<prefix[node].size(); i++)
    {
        prefix[node][i]=max(prefix[node][i], prefix[node][i-1]);
    }
    for (int i=suffix[node].size()-2; i>=0; i--)
    {
        suffix[node][i]=max(suffix[node][i], suffix[node][i+1]);
    }

    partial[node]=partial[parent];
    if (node!=1)
    {
        partial[node]=max(partial[node], max(prefix[parent][ind[node]], suffix[parent][ind[node]+1])+1);
        partial[node]++;
    }

    ans[node]=max(depth[node], partial[node]);

    for (auto &i: adj[node])
    {
        if (i!=parent)
        {
            solve(i, node);
        }
    }
}

int main()
{
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    solve(1, 0);

    for (int i=1; i<=n; i++)
    {
        cout << ans[i] << " ";
        // cout << partial[i] << endl;
    }
    cout << endl;

    return 0;
}

/*
5
1 2
1 3
3 4
3 5

10
9 7
8 10
3 6
7 1
4 9
3 5
10 4
5 2
8 6
*/