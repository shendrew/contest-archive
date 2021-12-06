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

ifstream fin("gates.in");
ofstream fout("gates.out");

#define f first
#define s second
#define ll long long

int n, ans;
string str;
int vis[1005][1005];
map<vector<int>, int> fence;

int main()
{
    fin >> n >> str;
    int x=1002, y=1002, lx=2005, ly=2005, hx=0, hy=0;
    for (int i=0; i<n; i++)
    {
        if (str[i]=='N')
        {
            fence[{x, y+1, x+1, y+1}]=1;
            fence[{x+1, y+1, x, y+1}]=1;
            y++;
        }
        else if (str[i]=='S')
        {
            fence[{x, y, x+1, y}]=1;
            fence[{x+1, y, x, y}]=1;
            y--;
        }
        else if (str[i]=='E')
        {
            fence[{x+1, y, x+1, y+1}]=1;
            fence[{x+1, y+1, x+1, y}]=1;
            x++;
        }
        else if (str[i]=='W')
        {
            fence[{x, y, x, y+1}]=1;
            fence[{x, y+1, x, y}]=1;
            x--;
        }
        lx=min(lx, x-1);
        ly=min(ly, y-1);
        hx=max(hx, x+1);
        hy=max(hy, y+1);
    }

    for (int i=0; i<hx-lx+5; i++)
    {
        for (int j=0; j<hy-ly+5; j++)
        {
            if (!vis[i][j])
            {
                ans++;
                stack<pair<int, int>> stk;
                stk.push({i, j});
                while (stk.size())
                {
                    pair<int, int> cur=stk.top();
                    int r=cur.f, c=cur.s;
                    stk.pop();
                    if ((r<0 || c<0 || r>=hx-lx+5 || c>=hy-ly+5) || vis[r][c])
                    {
                        continue;
                    }
                    vis[r][c]=1;
                    if (!fence[{r+lx, c+ly, r+1+lx, c+ly}])
                        stk.push({r+1, c});
                    if (!fence[{r+lx, c+ly, r-1+lx, c+ly}])
                        stk.push({r-1, c});
                    if (!fence[{r+lx, c+ly, r+lx, c+1+ly}])
                        stk.push({r, c+1});
                    if (!fence[{r+lx, c+ly, r+lx, c-1+ly}])
                        stk.push({r, c-1});
                }
            }
        }
    }

    fout << ans-1 << endl;

    return 0;
}