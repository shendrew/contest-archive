#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

#define f first
#define s second
int n, m, k;
int a[502][502], visit[502][502];
queue<pair<int,int>> que;
vector<pair<int,int>> path;

void floodfill(pair<int, int> cur, int r, int c)
{
    if (!visit[cur.f+r][cur.s+c] && a[cur.f+r][cur.s+c])
    {
        que.push({cur.f+r, cur.s+c});
        visit[cur.f+r][cur.s+c]=1;
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i=0; i<n; i++)
    {
        string str;
        cin >> str;
        for (int j=0; j<m; j++)
        {
            if (str[j]=='.')
            {
                a[i+1][j+1]=1;
            }
        }
    }
    
    bool done=false;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i][j])
            {
                que.push({i, j});
                visit[i][j]=1;
                while (que.size())
                {
                    pair<int, int> cur=que.front();
                    path.push_back(cur);
                    que.pop();
                    floodfill(cur, 1, 0);
                    floodfill(cur, -1, 0);
                    floodfill(cur, 0, 1);
                    floodfill(cur, 0, -1);
                }
                done=true;
                break;
            }
        }
        if (done)
        {
            break;
        }
    }

    for (int i=1; i<=k; i++)
    {
        a[path[path.size()-i].f][path[path.size()-i].s]=2;
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (!a[i][j])
            {
                cout << '#';
            }
            else if (a[i][j]==1)
            {
                cout << '.';
            }
            else
            {
                cout << 'X';
            }
        }
        cout << endl;
    }

    return 0;
}

/*
3 4 2
#..#
..#.
#...
*/