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

ifstream fin("mootube.in");
ofstream fout("mootube.out");

#define f first
#define s second
#define ll long long

int n, q, ki, cnt;
vector<pair<int, int>> adj[5003];
int visit[5003];

void dfs(int node, int rel)
{
    if (visit[node] || rel<ki)
    {
        return;
    }
    visit[node]=1;
    cnt++;
    for (auto &i: adj[node])
    {
        dfs(i.f, min(rel, i.s));
    }
}

int main()
{
    fin >> n >> q;
    for (int i=0; i<n-1; i++)
    {
        int p, q, r;
        fin >> p >> q >> r;
        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }

    for (int i=0; i<q; i++)
    {
        memset(visit, 0, sizeof(visit));
        int v;
        fin >> ki >> v;
        cnt=0;
        dfs(v, 2e9);
        fout << cnt-1 << endl;
    }

    return 0;
}