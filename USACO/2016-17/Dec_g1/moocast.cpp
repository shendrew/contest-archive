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
#include <functional>
using namespace std;

ifstream fin("moocast.in");
ofstream fout("moocast.out");

#define f first
#define s second
#define ll long long

int n;
int x[1000], y[1000];

int main()
{
    fin >> n;
    for (int i=0; i<n; i++)
    {
        fin >> x[i] >> y[i];
    }

    int low=0, high=1e9;
    while (low<high)
    {
        int mid=low+(high-low)/2;
        vector<int> visited(n+1);
        vector<vector<int>> graph(n+1);
        int cnt=0;

        function<void (int)> dfs;
        dfs = [&](int node)
        {
            visited[node]=1;
            cnt++;
            for (auto &i: graph[node])
            {
                if (!visited[i])
                {
                    dfs(i);
                }
            }
        };

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (i==j)
                {
                    continue;
                }
                if (pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2)<=mid)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        dfs(0);

        if (cnt==n)
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    fout << low << endl;


    return 0;
}