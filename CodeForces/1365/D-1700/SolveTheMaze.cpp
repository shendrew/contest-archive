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
using namespace std;

#define f first
#define s second
#define ll long long
int t, n, m, cnt;
int a[52][52], visit[52][52];

int check(int r, int c)
{
    if (!visit[r][c] && a[r][c])
    {
        return true;
    }
    return false;
}

void dfs(int r, int c)
{
    if (a[r][c]==2)
    {
        cnt++;
    }
    visit[r][c]=1;
    if (check(r-1, c))
        dfs(r-1, c);
    if (check(r, c+1))
        dfs(r, c+1);
    if (check(r+1, c))
        dfs(r+1, c);
    if (check(r, c-1))
        dfs(r, c-1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(visit, 0, sizeof(visit));

        vector<pair<int, int>> good, bad;
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
                else if (str[j-1]=='G')
                {
                    a[i][j]=2;
                    good.push_back({i, j});
                }
                else if (str[j-1]=='B')
                {
                    a[i][j]=3;
                    bad.push_back({i, j});
                }
                else
                {
                    a[i][j]=0;
                }
            }
        }
        
        bool possible=true;
        for (auto &i: bad)
        {
            if (a[i.f+1][i.s]==2 || (i.f+1==n && i.s==m))
                possible=false;
            else if (a[i.f+1][i.s]<2)
                a[i.f+1][i.s]=0;
            if (a[i.f-1][i.s]==2 || (i.f-1==n && i.s==m))
                possible=false;
            else if (a[i.f-1][i.s]<2)
                a[i.f-1][i.s]=0;
            if (a[i.f][i.s+1]==2 || (i.f==n && i.s+1==m))
                possible=false;
            else if (a[i.f][i.s+1]<2)
                a[i.f][i.s+1]=0;
            if (a[i.f][i.s-1]==2 || (i.f==n && i.s-1==m))
                possible=false;
            else if (a[i.f][i.s-1]<2)
                a[i.f][i.s-1]=0;
        }

        if (possible || !good.size())
        {
            cnt=0;
            dfs(n, m);

            if (cnt==good.size())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*
6
1 1
.
1 2
G.
2 2
#B
G.
2 3
G.#
B#.
3 3
#B.
#..
GG.
2 2
#B
B.
*/