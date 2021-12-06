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

int n, m;
vector<int> graph[100005];
bool possible=true;
int vis[100005];

void dfs(int node, int color)
{
    vis[node]=color;
    for (auto &i: graph[node])
    {
        if (!vis[i])
        {
            dfs(i, color^3);
        }
        else if (vis[i]==color)
        {
            possible=false;
            return;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=1; i<=n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 1);
        }
        if (!possible)
        {
            break;
        }
    }

    if (!possible)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i=1; i<=n; i++)
        {
            cout << vis[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

/*
5 3
1 2
1 3
4 5
*/