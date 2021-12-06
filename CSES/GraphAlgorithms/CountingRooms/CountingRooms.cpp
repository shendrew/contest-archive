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

#define f first
#define s second
#define ll long long

int n, m, ans;
int a[1003][1003], vis[1003][1003];

void flood(int r, int c)
{
    if (!a[r][c] || vis[r][c])
    {
        return;
    }
    vis[r][c]=1;
    flood(r+1, c);
    flood(r-1, c);
    flood(r, c+1);
    flood(r, c-1);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        string str;
        cin >> str;
        for (int j=1; j<=m; j++)
        {
            if (str[j-1]=='.')
            {
                a[i][j]=1;
            }
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (!vis[i][j] && a[i][j])
            {
                ans++;
                flood(i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}

/*
5 8
########
#..#...#
####.#.#
#..#...#
########
*/