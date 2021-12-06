#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define f first
#define s second
int n, m;
pair<int,int> a[100001];
vector<int> graph[100001];
bool visit[100001];

int main()
{
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    fin >> n >> m;
    int x, y, ans=1000000000;
    for (int i=1; i<=n; i++)
    {
        fin >> x >> y;
        a[i]={x,y};
    }
    for (int i=0; i<m; i++)
    {
        fin >> x >> y;
        graph[x].push_back(y), graph[y].push_back(x);
    }

    for (int i=1; i<=n; i++)
    {
        if (!visit[i])
        {
            int left=a[i].f, right=a[i].f, up=a[i].s, down=a[i].s;
            queue<int> que;
            que.push(i);
            visit[i]=true;
            while (que.size())
            {
                int cur=que.front();
                que.pop();
                for (int j=0; j<graph[cur].size(); j++)
                {
                    if (!visit[graph[cur][j]])
                    {
                        visit[graph[cur][j]]=true;
                        que.push(graph[cur][j]);
                        left=min(left, a[graph[cur][j]].f), right=max(right, a[graph[cur][j]].f);
                        down=min(down, a[graph[cur][j]].s), up=max(up, a[graph[cur][j]].s);
                    }
                }
            }
            ans=min(ans, 2*(right-left)+2*(up-down));
        }
    }
    fout << ans << endl;

    return 0;
}
