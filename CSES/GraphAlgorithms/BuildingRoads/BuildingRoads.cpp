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
vector<int> graph[100005];

void dfs(int node)
{
    visited[node]=1;
    for (auto &i: graph[node])
    {
        if (!visited[i])
        {
            dfs(i);
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
        graph[a].push_back(b), graph[b].push_back(a);
    }

    vector<int> start;
    for (int i=1; i<=n; i++)
    {
        if (!visited[i])
        {
            start.push_back(i);
            dfs(i);
        }
    }

    cout << start.size()-1 << endl;
    for (int i=1; i<start.size(); i++)
    {
        cout << start[0] << " "<< start[i] << endl;
    }

    return 0;
}

/*
4 2
1 2
3 4
*/