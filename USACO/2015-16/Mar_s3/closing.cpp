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

ifstream fin("closing.in");
ofstream fout("closing.out");

#define f first
#define s second
#define ll long long

int n, m;
int counter;
int closed[3003], visited[3003];
vector<int> graph[3003];

void bfs(int node)
{
    visited[node]=true;
    counter++;
    for (auto &i: graph[node])
    {
        if (!closed[i] && !visited[i])
        {
            bfs(i);
        }
    }
}

int main()
{
    fin >> n >> m;
    set<int> barns;
    for (int i=0; i<=n; i++)
    {
        barns.insert(i);
    }

    for (int i=0; i<m; i++)
    {
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b), graph[b].push_back(a);
    }

    vector<int> close(n);
    for (int i=1; i<=n; i++)
    {
        fin >> close[i];
    }

    for (int i=0; i<n; i++)
    {
        barns.erase(close[i]);
        closed[close[i]]++;
        counter=0;
        memset(visited, 0, sizeof(visited));
        bfs(*barns.begin());
        if (counter==barns.size())
        {
            fout << "YES" << endl;
        }
        else
        {
            fout << "NO" << endl;
        }
    }

    return 0;
}