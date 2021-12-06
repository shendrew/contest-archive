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
using namespace std;

#define f first
#define s second
#define ll long long

int n, m;
int visited[100005];
vector<int> graph[100005][2];

void dfs(int node, int direction)
{
    visited[node]=1;
    for (auto &i: graph[node][direction])
    {
        if (!visited[i])
        {
            dfs(i, direction);
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
        graph[a][0].push_back(b);
        graph[b][1].push_back(a);
    }
    
    dfs(1, 0);
    for (int i=1; i<=n; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl << 1 << " " << i << endl;
            return 0;
        }
    }

    memset(visited, 0, sizeof(visited));

    dfs(1, 1);
    for (int i=1; i<=n; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}

/*
4 5
1 2
2 3
3 1
1 4
3 4
*/