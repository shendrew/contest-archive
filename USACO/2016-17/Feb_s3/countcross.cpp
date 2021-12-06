#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

#define f first
#define s second
int n, k, r, ans;
set<vector<int>> road;
vector<pair<int,int>> vp;
int visit[102][102];
queue<pair<int,int>> que;

void checkRoad(int r1, int c1, int r2, int c2)
{
    if (r2>0 && r2<=n && c2>0 && c2<=n)
    {
        if (!visit[r2][c2] && !road.count({r1,c1,r2,c2}))
        {
            que.push({r2,c2});
            visit[r2][c2]=1;
        }
    }
}

int main()
{
    chdir("/Users/andrews/Desktop/Andrew_Folder/c++Code/USACO/2016-17/Feb_s3");
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");

    fin >> n >> k >> r;
    for (int i=0; i<r; i++)
    {
        int r1, c1, r2, c2;
        fin >>  r1 >> c1 >> r2 >> c2;
        road.insert({r1,c1,r2,c2});
        road.insert({r2,c2,r1,c1});
    }
    vp.resize(k);
    for (int i=0; i<k; i++)
    {
        fin >> vp[i].f >> vp[i].s;
    }

    for (int i=0; i<k; i++)
    {
        for (int j=1; j<=n; j++)
            for (int e=1; e<=n; e++)
                visit[j][e]=0;

        que={};
        que.push({vp[i].f, vp[i].s});
        visit[vp[i].f][vp[i].s]=1;
        while (que.size())
        {
            pair<int,int> cur=que.front();
            que.pop();
            checkRoad(cur.f, cur.s, cur.f-1, cur.s);
            checkRoad(cur.f, cur.s, cur.f+1, cur.s);
            checkRoad(cur.f, cur.s, cur.f, cur.s-1);
            checkRoad(cur.f, cur.s, cur.f, cur.s+1);
        }
        for (int j=0; j<k; j++)
        {
            if (i!=j && !visit[vp[j].f][vp[j].s])
            {
                ans++;
            }
        }
    }
    fout << ans/2;
    return 0;
}
