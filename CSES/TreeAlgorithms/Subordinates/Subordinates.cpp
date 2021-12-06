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
int ans[200005];

int dfs(int node)
{
    int ret=1;
    for (auto &i: adj[node])
    {
        ret+=dfs(i);
    }
    ans[node]=ret-1;
    return ret;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=2; i<=n; i++)
    {
        int ai;
        cin >> ai;
        adj[ai].push_back(i);
    }

    dfs(1);

    for (int i=1; i<=n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
5
1 1 2 3
*/