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

ifstream fin("lightson.in");
ofstream fout("lightson.out");

#define f first
#define s second
#define ll long long

int n, m, ans;
vector<pair<int, int>> adj[105][105];
int color[105][105], vis[105][105];

void dfs(int r, int c)
{
    if (!color[r][c] || vis[r][c])
    {
        return;
    }
    vis[r][c]=1;
    for (auto &i: adj[r][c])
    {
        if (!color[i.f][i.s])
        {
            color[i.f][i.s]=1;
            ans++;
            if (vis[i.f+1][i.s] || vis[i.f-1][i.s] || vis[i.f][i.s+1] || vis[i.f][i.s-1])
            {
                dfs(i.f, i.s);
            }
        }
    }
    dfs(r+1, c);
    dfs(r-1, c);
    dfs(r, c+1);
    dfs(r, c-1);
}

int main()
{
    fin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        adj[x][y].push_back({a, b});
    }
    
    ans=1;
    color[1][1]=1;
    dfs(1, 1);

    fout << ans << endl;

    return 0;
}