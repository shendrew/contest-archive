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

long long n, ans, odd, even;
vector<int> graph[100005];
int vis[100005];

void dfs(int node, int color)
{
    vis[node]=color;
    if (color==1)
    {
        odd++;
    }
    else
    {
        even++;
    }
    for (auto &i: graph[node])
    {
        if (!vis[i])
        {
            dfs(i, color^3);
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
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);

    cout << odd*even-(n-1) << endl;

    return 0;
}

/*
5
1 2
2 3
3 4
4 5
*/