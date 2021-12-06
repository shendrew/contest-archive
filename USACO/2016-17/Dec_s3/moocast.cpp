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

ifstream fin("moocast.in");
ofstream fout("moocast.out");

#define f first
#define s second
#define ll long long

int n, ans;
vector<int> graph[202];
int visited[202];
int counter;

void bfs(int node)
{
    visited[node]++;
    counter++;
    for (auto &i: graph[node])
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }
}

int main()
{
    fin >> n;
    vector<int> x(n), y(n), power(n);
    for (int i=0; i<n; i++)
    {
        fin >> x[i] >> y[i] >> power[i];
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i!=j && power[i]>sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2)))
            {
                graph[i].push_back(j);
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        counter=0;
        memset(visited, 0, sizeof(visited));
        bfs(i);
        ans=max(ans, counter);
    }

    fout << ans << endl;

    return 0;
}