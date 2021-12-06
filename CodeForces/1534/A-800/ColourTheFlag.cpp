#include <iostream>
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
int t, n, m;
int a[52][52];
queue<pair<int,int>> que;
map<pair<int,int>, int> visit;
bool possible=true;
pair<int, int> cur;

void add(int r, int c)
{
    if (r && c && r<=n && c<=m && !visit[{r, c}])
    {
        if (a[r][c] && a[r][c]==a[cur.f][cur.s])
        {
            possible=false;
        }
        que.push({r, c});
        visit[{r, c}]=1;
        a[r][c]=(a[cur.f][cur.s]^3);
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i=0; i<=51; i++)
        {
            for (int j=0; j<=51; j++)
            {
                a[i][j]=0;
            }
        }
        cin >> n >> m;
        bool color=false;
        for (int i=1; i<=n; i++)
        {
            string str;
            cin >> str;
            for (int j=1; j<=m; j++)
            {
                if (str[j-1]=='R')
                {
                    a[i][j]=1;
                    color=true;
                }
                else if (str[j-1]=='W')
                {
                    a[i][j]=2;
                    color=true;
                }
            }
        }

        if (!color)
        {
            a[1][1]=1;
        }
        visit={};
        possible=true;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m ; j++)
            {
                if (a[i][j] && !visit[{i, j}])
                {
                    que={};
                    que.push({i, j});
                    visit[{i, j}]=1;
                    while (que.size() && possible)
                    {
                        cur=que.front();
                        que.pop();
                        add(cur.f+1, cur.s);
                        add(cur.f-1, cur.s);
                        add(cur.f, cur.s+1);
                        add(cur.f, cur.s-1);
                    }
                }
                if (!possible)
                {
                    break;
                }
            }
            if  (!possible)
            {
                break;
            }
        }

        if (possible)
        {
            cout << "YES" << endl;
            for (int i=1; i<=n; i++)
            {
                for (int j=1; j<=m; j++)
                {
                    if (a[i][j]==1)
                    {
                        cout << "R";
                    }
                    else if (a[i][j]==2)
                    {
                        cout << "W";
                    }
                }
                cout << endl;
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
3
4 6
.R....
......
......
.W....
4 4
.R.W
....
....
....
5 1
R
W
R
W
R
*/