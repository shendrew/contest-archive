#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream fin("revegetate.in");
ofstream fout("revegetate.out");

int n, m, ans;
int field[100001];
bool done[100001], visited[100001];
vector<pair<int,char>> graph[100001];

int main()
{
    fin >> n >> m;
    char chr;
    int i, j, x, y;
    for (i=1; i<=m; i++)
    {
        fin >> chr >> x >> y;
        graph[x].push_back(make_pair(y,chr)), graph[y].push_back(make_pair(x,chr));
    }
    bool possible=true;
    for (i=1; i<=n; i++)
    {
        if (done[i])
        {
            continue;
        }
        field[i]=1;
        stack<int> stk;
        stk.push(i);
        vector<int> path;
        while(stk.size()>0 && possible)
        {
            int current=stk.top();
            stk.pop();
            for (j=0; j<graph[current].size(); j++)
            {
                visited[current]=true;
                path.push_back(current);
                if (visited[graph[current][j].first]==false)
                {
                    stk.push(graph[current][j].first);
                    if (!field[graph[current][j].first])
                    {
                        if (graph[current][j].second=='S')
                            field[graph[current][j].first]=field[current];
                        else if (graph[current][j].second=='D')
                            field[graph[current][j].first]=3-field[current];
                    }
                    else if (field[graph[current][j].first])
                    {
                        if ((field[graph[current][j].first]==field[current] && graph[current][j].second=='D') || (field[graph[current][j].first]!=field[current] && graph[current][j].second=='S'))
                        {
                            possible=false;
                            break;
                        }
                    }
                }
            }
        }
        if (!possible) break;
        for (j=0; j<path.size(); j++)
        {
            visited[path[j]]=false;
            done[path[j]]=true;
        }
        ans++;
    }
    //cout << ans;
    if (possible)
    {
        fout << 1;
        for (i=0; i<ans; i++)
        {
            fout << 0;
        }
    }
    else
    {
        fout << 0;
    }
    return 0;
}
