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
int nxt[200005], vis[200005], ans[200005], dist[200005];

int solve(int node, int d)
{
    if (vis[node])
    {
        if (ans[node])
        {
            return 1; // exist
        }
        else
        {
            ans[node]=d-dist[node];
            return 0; // loop
        }
    }
    
    vis[node]++;
    dist[node]=d;
    int res=solve(nxt[node], d+1);
    if (vis[node] && ans[node])
    {
        return 1;
    }
    if (res)
    {
        ans[node]=ans[nxt[node]]+1;
    }
    else
    {
        ans[node]=ans[nxt[node]];
    }
    return res;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> nxt[i];
    }

    for (int i=1; i<=n; i++)
    {
        if (!vis[i])
        {
            solve(i, 0);
        }
    }

    for (int i=1; i<=n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
5
2 4 3 1 4
*/