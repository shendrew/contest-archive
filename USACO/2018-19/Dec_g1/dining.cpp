#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define f first
#define s second
int n, m, k;
int dist[50001];
vector<int> edge[50001];
map<pair<int,int>, int> weight;

void dijkstra(int start)
{
    queue<int> que;
    que.push(start);
    while (que.size())
    {
        int cur=que.front();
        que.pop();
        for (int i=0; i<edge[cur].size(); i++)
        {
            int leaf=edge[cur][i];
            if (leaf!=start && (dist[leaf]==0 || dist[cur]+weight[{cur,leaf}]<dist[leaf]))
            {
                que.push(leaf);
                dist[leaf]=dist[cur]+weight[{cur,leaf}];
            }
        }
    }
}

int main()
{
    ifstream fin("dining.in");
    ofstream fout("dining.out");

    fin >> n >> m >> k;
    for (int i=0; i<m; i++)
    {
        int x, y, w;
        fin >> x >> y >> w;
        edge[x].push_back(y), edge[y].push_back(x);
        weight[{x,y}]=w, weight[{y,x}]=w;
    }
    dijkstra(n);
    for (int i=1; i<=n; i++)
    {
        fout << dist[i] << endl;
    }

    return 0;
}
