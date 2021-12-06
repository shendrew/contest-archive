#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

#define f first
#define s second
int n, k;
long long sum;
vector<int> edge[200001];
bool visit[200001];
int depth[200001], children[200001];

int dfs(int cur, int dpt)
{
    depth[cur]=dpt;
    visit[cur]=true;
    int child=0;
    for (int i=0; i<edge[cur].size(); i++)
    {
        if (!visit[edge[cur][i]])
        {
            child+=dfs(edge[cur][i], dpt+1)+1;
        }
    }
    visit[cur]=false;
    children[cur]=child;
    return child;
}

int main()
{
    cin >> n >> k;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b), edge[b].push_back(a);
    }

    dfs(1, 0);

    vector<int> happy;
    for (int i=1; i<=n; i++)
    {
        happy.push_back(children[i]-depth[i]);
    }
    sort(happy.begin(), happy.end(), greater<int>());

    for (int i=0; i<n-k; i++)
    {
        sum+=happy[i];
    }

    cout << sum << endl;

    return 0;
}

/*
7 4
1 2
1 3
1 4
3 5
3 6
4 7
*/