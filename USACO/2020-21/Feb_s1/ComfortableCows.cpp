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
int n, ans;
int a[3000][3000];
queue<pair<int,int>> que;

void add(int x, int y)
{
    if (!a[x][y])
    {
        a[x][y]=1;
        ans++;
        que.push({x,y});
    }
}

void check(int x, int y)
{
    if (a[x+1][y]+a[x-1][y]+a[x][y+1]+a[x][y-1]==3)
    {
        add(x+1, y);
        add(x-1, y);
        add(x, y+1);
        add(x, y-1);
    }
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        x+=1000, y+=1000;
        if (a[x][y])
        {
            ans--;
        }
        else
        {
            a[x][y]=1;

            que={};
            que.push({x,y});
            while (que.size())
            {
                pair<int,int> cur=que.front();
                que.pop();
                check(cur.f+1, cur.s);
                check(cur.f-1, cur.s);
                check(cur.f, cur.s+1);
                check(cur.f, cur.s-1);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
/*
9
0 1
1 0
1 1
1 2
2 1
2 2
3 1
3 2
4 1
*/