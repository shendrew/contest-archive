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

ifstream fin("truth.in");
ofstream fout("truth.out");

int n, m;
int a[10004], b[10004], state[10004], vis[1003];
vector<pair<int, int>> adj[1003];

bool dfs(int node, int truth)
{
    bool ret=true;
    if (vis[node]!=0)
    {
        if (vis[node]!=truth)
        {
            return false;
        }
        return true;
    }
    vis[node]=truth;
    for (auto &i: adj[node])
    {
        ret*=dfs(i.f, vis[node]*i.s);
    }
    return ret;
}

int main()
{
    fin >> n >> m;
    for (int i=0; i<m; i++)
    {
        char str;
        fin >> a[i] >> b[i] >> str;
        if (str=='T')
            state[i]=1;
        else
            state[i]=-1;
    }

    int low=1, high=m;
    while (low<high)
    {
        int mid=(low+high+1)/2;
        for (int i=1; i<=n; i++)
        {
            vis[i]=0;
            adj[i]={};
        }

        for (int i=0; i<mid; i++)
        {
            adj[a[i]].push_back({b[i], state[i]});
            adj[b[i]].push_back({a[i], state[i]});
        }

        bool possible=true;
        for (int i=1; i<=n; i++)
        {
            if (!vis[i])
            {
                possible*=dfs(i, 1);
            }
        }
        if (possible)
        {
            low=mid;
        }
        else
        {
            high=--mid;
        }
    }
    fout << low << endl;

    return 0;
}