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
int a[1003], vis[1003], ans[1003];

int dfs(int node)
{
    if (ans[node])
    {
        return ans[node];
    }
    if (vis[node])
    {
        ans[node]=node;
        return -1;
    }

    vis[node]++;
    int ret=dfs(a[node]);
    if (ans[node])
    {
        ret=ans[node];
    }

    if (ret==-1)
    {
        ans[node]=node;
    }
    else
    {
        ans[node]=ret;
    }
    return ret;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    
    for (int i=1; i<=n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
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
3
2 3 2
*/