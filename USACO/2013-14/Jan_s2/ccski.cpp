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

ifstream fin("ccski.in");
ofstream fout("ccski.out");

#define f first
#define s second
#define ll long long

int n, m, cnt, d;
int a[502][502], way[502][502], vis[502][502];
pair<int, int> start;

void flood(int r, int c)
{
    if (a[r][c]==-1 || vis[r][c])
    {
        return;
    }
    vis[r][c]=1;
    if (way[r][c])
    {
        cnt++;
    }
    if (abs(a[r][c]-a[r+1][c])<=d)
    {
        flood(r+1, c);
    }
    if (abs(a[r][c]-a[r-1][c])<=d)
    {
        flood(r-1, c);
    }
    if (abs(a[r][c]-a[r][c+1])<=d)
    {
        flood(r, c+1);
    }
    if (abs(a[r][c]-a[r][c-1])<=d)
    {
        flood(r, c-1);
    }
}

int main()
{
    fin >> n >> m;
    memset(a, -1, sizeof(a));
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            fin >> a[i][j];
        }
    }

    int point=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            fin >> way[i][j];
            if (way[i][j]==1)
            {
                start={i, j};
                point++;
            }
        }
    }

    int low=0, high=1000000009, mid;
    while (low<high)
    {
        memset(vis, 0, sizeof(vis));
        mid=low+(high-low)/2;
        cnt=0;
        d=mid;
        flood(start.f, start.s);
        if (cnt==point)
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    fout << mid << endl;

    return 0;
}