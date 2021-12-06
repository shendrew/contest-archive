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

int n, ans;
vector<int> adj[10004];
int vis[10004];

void dfs(int node)
{
    if (vis[node])
    {
        return;
    }
    vis[node]=1;
    for (auto &i: adj[node])
    {
        dfs(i);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        a--;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    for (int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs(i);
        }
    }

    cout << ans << endl;

    return 0;
}

/*
5
2 1 5 3 3
*/