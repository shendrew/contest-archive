#include <iostream>
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
using namespace std;

#define f first
#define s second
int t;
int visit[100001];
vector<vector<int>> lr;
vector<vector<int>> vvi;
map<pair<int, int>, long long> dp, record;

long long solve(int cur, int a)
{
    if (record[{cur, a}])
    {
        return dp[{cur, a}];
    }
    long long ret=0;
    visit[cur]=1;
    for (int i=0; i<vvi[cur].size(); i++)
    {
        int next=vvi[cur][i];
        if (!visit[next])
        {
            ret+=max(abs(lr[cur][a]-lr[next][0])+solve(vvi[cur][i], 0), abs(lr[cur][a]-lr[next][1])+solve(vvi[cur][i], 1));
        }
    }
    visit[cur]=0;
    record[{cur, a}]=1;

    return dp[{cur, a}]=ret;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        lr.clear(), vvi.clear(), dp.clear(), record.clear();
        int n;
        scanf("%d", &n);
        lr.resize(n+1), vvi.resize(n+1);
        for (int i=1; i<=n; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            lr[i].push_back(l), lr[i].push_back(r);
        }
        for (int i=0; i<n-1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            vvi[u].push_back(v), vvi[v].push_back(u);
        }
        printf("%lld\n", max(solve(1, 0), solve(1, 1)));
    }

    return 0;
}

/*
3
2
1 6
3 8
1 2
3
1 3
4 6
7 9
1 2
2 3
6
3 14
12 20
12 19
2 12
10 17
3 17
3 2
6 5
1 5
2 6
4 6
*/