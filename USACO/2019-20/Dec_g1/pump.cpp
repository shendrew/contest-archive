#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

#define f first
#define s second
int n, m;
vector<pair<int,pair<double,double>>> a[10001];
double weight[10001], flow[10001];
long long cost[10001];

int main()
{
    ifstream fin("pump.in");
    ofstream fout("pump.out");

    fin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int x, y, c, fl;
        fin >> x >> y >> c >> fl;
        a[x].push_back({y,{fl,c}}), a[y].push_back({x,{fl,c}});
    }

    queue<int> que;
    que.push(1);
    flow[1]=10001;
    while (que.size())
    {
        int cur=que.front();
        que.pop();
        for (int i=0; i<a[cur].size(); i++)
        {
            if (min(flow[cur], a[cur][i].s.f)/(cost[cur]+a[cur][i].s.s)>weight[a[cur][i].f])
            {
                que.push(a[cur][i].f);
                flow[a[cur][i].f]=min(flow[cur], a[cur][i].s.f);
                cost[a[cur][i].f]=cost[cur]+a[cur][i].s.s;
                weight[a[cur][i].f]=flow[a[cur][i].f]/cost[a[cur][i].f];
            }
        }
    }

    fout << int(1000000*weight[n]) << endl;
    return 0;
}
