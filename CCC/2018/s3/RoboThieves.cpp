#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

#define f first
#define s second

int n, m;
pair<int,int> start;
vector<string> v;
set<pair<int,int>> watched;
vector<pair<int,int>> graph[100][100];
int cost[100][100];

void camera(int y, int x)
{
    int yi=y, xi=x;
    while (v[yi][xi]!='W')
    {
        yi--;
        if (v[yi][xi]=='.'||v[yi][xi]=='S')
            watched.insert(make_pair(yi, xi));
    }
    yi=y;
    while (v[yi][xi]!='W')
    {
        yi++;
        if (v[yi][xi]=='.'||v[yi][xi]=='S')
            watched.insert(make_pair(yi, xi));
    }
    yi=y;
    while (v[yi][xi]!='W')
    {
        xi++;
        if (v[yi][xi]=='.'||v[yi][xi]=='S')
            watched.insert(make_pair(yi, xi));
    }
    xi=x;
    while (v[yi][xi]!='W')
    {
        xi--;
        if (v[yi][xi]=='.'||v[yi][xi]=='S')
            watched.insert(make_pair(yi, xi));
    }
}
pair<int,int> check(int a, int b)
{
    set<pair<int,int>> loop;
    while (!loop.count(make_pair(a,b)) && !watched.count(make_pair(a, b)) && v[a][b]!='W' && v[a][b]!='C')
    {
        if (v[a][b]=='.')
        {
            return make_pair(a,b);
        }
        loop.insert(make_pair(a,b));
        if (v[a][b]=='L')
            b--;
        else if (v[a][b]=='R')
            b++;
        else if (v[a][b]=='U')
            a--;
        else if (v[a][b]=='D')
            a++;

    }
    return make_pair(0,0);
}
void neighbour(int y, int x)
{
    if (check(y-1,x).f && check(y-1,x).s)
        graph[y][x].push_back(check(y-1,x));
    if (check(y+1,x).f && check(y+1,x).s)
        graph[y][x].push_back(check(y+1,x));
    if (check(y,x-1).f && check(y,x-1).s)
        graph[y][x].push_back(check(y,x-1));
    if (check(y,x+1).f && check(y,x+1).s)
        graph[y][x].push_back(check(y,x+1));
}

int main() {
    cin >> n >> m;
    v.resize(n);
    int i, j;
    for (i=0; i<n; i++)
    {
        cin >> v[i];
    }
    for (i=1; i<n-1; i++)
    {
        for (j=1; j<m-1; j++)
        {
            cost[i][j]=-100000;
            if (v[i][j]=='C')
            {
                camera(i,j);
            }
            else if (v[i][j]=='S')
            {
                start=make_pair(i, j);
                cost[i][j]=0;
            }
        }
    }
    for (i=1; i<n-1; i++)
    {
        for (j=1; j<m-1; j++)
        {
            if ((v[i][j]=='.' || v[i][j]=='S') && !watched.count(make_pair(i,j)))
            {
                neighbour(i, j);
            }
        }
    }
    
    queue<pair<int,int>> que;
    que.push(start);
    while(que.size())
    {
        pair<int,int> top=que.front();
        que.pop();
        for (i=0; i<graph[top.f][top.s].size(); i++)
        {
            if (cost[top.f][top.s]+1<abs(cost[graph[top.f][top.s][i].f][graph[top.f][top.s][i].s]))
            {
                que.push(graph[top.f][top.s][i]);
                cost[graph[top.f][top.s][i].f][graph[top.f][top.s][i].s]=cost[top.f][top.s]+1;
            }
        }
    }
    for (i=1; i<n-1; i++)
    {
        for (j=1; j<m-1; j++)
        {
            if (v[i][j]=='.')
            {
                if (cost[i][j]<0)
                    cout << -1 << endl;
                else
                    cout << cost[i][j] << endl;
            }
        }
    }
    
    return 0;
}

/*
5 7
WWWWWWW
WD.L.RW
W.WCU.W
WWW.S.W
WWWWWWW
*/
