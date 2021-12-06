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

#define f first
#define s second
#define ll long long

int n, m, maxDist, totalDist;
int found[100000], isPho[100000], counted[100000], numPho[100000], visit[100000];
vector<vector<int>> graph;

void calDist(int node, int d)
{
    visit[node]++;
    for (auto &i: graph[node])
    {
        if (!visit[i])
        {
            visit[i]++;
            if (numPho[i])
            {
                calDist(i, d+1);
                totalDist+=2;
            }
        }
    }
    maxDist=max(maxDist, d);
}

int countPho(int node)
{
    counted[node]++;
    int ret=0;
    if (isPho[node])
    {
        ret++;
    }
    for (auto &i: graph[node])
    {
        if (!counted[i])
        {
            counted[i]++;
            ret+=countPho(i);
        }
    }
    numPho[node]=ret;
    return ret;
}

vector<int> far(int node, int d)
{
    found[node]++;
    int curDist=d, ret=node;
    bool gotPho=false;
    for (auto &i: graph[node])
    {
        if (!found[i])
        {
            found[i]++;
            vector<int> res=far(i, d+1);
            if (res[1] > curDist && res[2])
            {
                gotPho=true;
                curDist=res[1];
                ret=res[0];
            }
        }
    }
    if (isPho[node] || gotPho)
    {
        return {ret, curDist, 1};
    }
    return {ret, curDist, 0};
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    graph.resize(n);
    vector<int> pho(m);
    for (int i=0; i<m; i++)
    {
        cin >> pho[i];
        isPho[pho[i]]++;
    }
    for (int i=0; i<n-1; i++)
    {
        int ai, bi;
        cin >> ai >> bi;
        graph[ai].push_back(bi);
        graph[bi].push_back(ai);
    }

    int start=far(pho[0], 0)[0];
    countPho(start);
    calDist(start, 0);

    cout << totalDist-maxDist << endl;

    return 0;
}

/*
8 2
5 2
0 1
0 2
2 3
4 3
6 1
1 5
7 3
*/