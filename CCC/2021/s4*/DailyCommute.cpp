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

int n, w, d;
set<int> adj[200005];
int vis[200005], dist[200005];

int main()
{
    cin >> n >> w >> d;
    for (int i=0; i<w; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].insert(a);
    }

    for (int i=0; i<=n; i++)
    {
        dist[i]=2000005;
    }

    queue<int> que;
    que.push(n);
    dist[n]=0;
    vis[n]=1;
    while (que.size())
    {
        int cur=que.front();
        que.pop();
        for (auto &i: adj[cur])
        {
            if (!vis[i])
            {
                dist[i]=dist[cur]+1;
                vis[i]=1;
                que.push(i);
            }
        }
    }

    vector<int> train(n);
    for (int i=0; i<n; i++)
    {
        cin >> train[i];
    }

    while (d--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int temp=train[x];
        train[x]=train[y], train[y]=temp;
        
        int ans=2000005;
        for (int i=0; i<n; i++)
        {
            ans=min(ans, i+dist[train[i]]);
        }
        cout << ans << endl;
    }

    return 0;
}

// min (time to station + station to finish)

/*
4 3 3
1 2
3 4
4 1
1 4 3 2
3 4
4 2
3 2
*/