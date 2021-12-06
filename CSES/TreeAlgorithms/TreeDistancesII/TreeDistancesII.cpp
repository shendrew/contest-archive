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
long long subtree[200005], ans[200005];

int sub(int node, int parent)
{
    for (auto &i: adj[node])
    {
        if (i!=parent)
        {
            subtree[node]+=sub(i, node);
        }
    }
    return subtree[node]+1;
}

long long dist(int node, int parent, long long d)
{
    long long ret=d;
    for (auto &i: adj[node])
    {
        if (i!=parent)
        {
            ret+=dist(i, node, d+1);
        }
    }
    return ret;
}

void solve(int node, int parent)
{
    if (parent!=-1)
    {
        ans[node]=ans[parent]+n-2*(subtree[node]+1);
    }

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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sub(1, -1);
    ans[1]=dist(1, -1, 0);
    solve(1, -1);

    for (int i=1; i<=n; i++)
    {
        cout << ans[i] << " ";
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
*/