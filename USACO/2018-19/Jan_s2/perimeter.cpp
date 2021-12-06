#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define f first
#define s second
int n, area, peri;
int a[1002][1002];
bool visit[1002][1002];

int main()
{
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    fin >> n;
    for (int i=1; i<=n; i++)
    {
        string str;
        fin >> str;
        for (int j=1; j<=n; j++)
        {
            if (str.substr(j-1, 1)==".")
                a[i][j]=0;
            else
                a[i][j]=1;
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (a[i][j] && !visit[i][j])
            {
                int aCount=0, pCount=0;
                queue<pair<int,int>> que;
                que.push({i,j});
                visit[i][j]=true;
                while (que.size())
                {
                    pair<int,int> cur=que.front();
                    que.pop();
                    aCount++;
                    if (a[cur.f-1][cur.s])
                    {
                        if (!visit[cur.f-1][cur.s])
                        {
                            que.push({cur.f-1,cur.s});
                            visit[cur.f-1][cur.s]=true;
                        }
                    }
                    else
                        pCount++;
                    if (a[cur.f+1][cur.s])
                    {
                        if (!visit[cur.f+1][cur.s])
                        {
                            que.push({cur.f+1,cur.s});
                            visit[cur.f+1][cur.s]=true;
                        }
                    }
                    else
                        pCount++;
                    if (a[cur.f][cur.s-1])
                    {
                        if (!visit[cur.f][cur.s-1])
                        {
                            que.push({cur.f,cur.s-1});
                            visit[cur.f][cur.s-1]=true;

                        }
                    }
                    else
                        pCount++;
                    if (a[cur.f][cur.s+1])
                    {
                        if (!visit[cur.f][cur.s+1])
                        {
                            que.push({cur.f,cur.s+1});
                            visit[cur.f][cur.s+1]=true;
                        }
                    }
                    else
                        pCount++;
                }
                if (aCount>area)
                {
                    area=aCount, peri=pCount;
                }
                else if (aCount==area)
                {
                    peri=min(peri, pCount);
                }
            }
        }
    }
    fout << area << " " << peri;

    return 0;
}
