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

int k, n, m, a, b;
vector<vector<int>> graph[2003];
int res[2003][202];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> k >> n >> m;
    for (int i=0; i<m; i++)
    {
        int ai, bi, t, h;
        cin >> ai >> bi >> t >> h;
        graph[ai].push_back({bi, t, h}), graph[bi].push_back({ai, t, h});
    }
    cin >> a >> b;

    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=k; j++)
        {
            res[i][j]=2e9;
        }
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que; // dist, node, hull (nonincreasing)
    que.push({0, a, 0});
    while (que.size())
    {
        vector<int> cur=que.top();
        int d=cur[0], node=cur[1], h=cur[2];
        que.pop();

        res[node][h]=min(res[node][h], d);
        if (node==b)
        {
            break;
        }
        
        for (auto &i: graph[node])
        {
            if (h+i[2]<k && d+i[1]<res[i[0]][h+i[2]])
            {
                que.push({d+i[1], i[0], h+i[2]});
            }
        }
    }

    int ans=2e9;
    for (int i=0; i<k; i++)
    {
        ans=min(ans, res[b][i]);
    }

    if (ans==2e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}

/*
10 4 7
1 2 4 4
1 3 7 2
3 1 8 1
3 2 2 2
4 2 1 6
3 4 1 1
1 4 6 12
1 4
*/