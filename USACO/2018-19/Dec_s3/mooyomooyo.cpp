#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define f first
#define s second
int n, m, k;
int a[102][102];

int main()
{
    ifstream fin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");

    fin >> n >> k;
    for (int i=1; i<=n; i++)
    {
        string s;
        fin >> s;
        m=s.size();
        for (int j=0; j<m; j++)
        {
            a[i][j+1]=stoi(s.substr(j,1));
        }
    }
    while (true)
    {
        int visit[102][102]={{0}};
        vector<pair<int,int>> blocks;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                if (a[i][j]==0)
                {
                    visit[i][j]=1;
                }
                else if (!visit[i][j])
                {
                    int type=a[i][j], group=0;
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    visit[i][j]=1;
                    while (que.size())
                    {
                        pair<int,int> cur=que.front();
                        que.pop();
                        group++;
                        blocks.push_back(cur);
                        if (!visit[cur.f-1][cur.s] && a[cur.f-1][cur.s]==type)
                        {
                            que.push({cur.f-1,cur.s});
                            visit[cur.f-1][cur.s]=1;
                        }
                        if (!visit[cur.f+1][cur.s] && a[cur.f+1][cur.s]==type)
                        {
                            que.push({cur.f+1,cur.s});
                            visit[cur.f+1][cur.s]=1;
                        }
                        if (!visit[cur.f][cur.s-1] && a[cur.f][cur.s-1]==type)
                        {
                            que.push({cur.f,cur.s-1});
                            visit[cur.f][cur.s-1]=1;
                        }
                        if (!visit[cur.f][cur.s+1] && a[cur.f][cur.s+1]==type)
                        {
                            que.push({cur.f,cur.s+1});
                            visit[cur.f][cur.s+1]=1;
                        }
                    }
                    if (group>0 && group<k)
                    {
                        for (int e=0; e<group; e++)
                        {
                            blocks.pop_back();
                        }
                    }
                }
            }
        }

        if (!blocks.size())
        {
            break;
        }
        for (int i=0; i<blocks.size(); i++)
        {
            a[blocks[i].f][blocks[i].s]=0;
        }
        for (int i=1; i<=m; i++)
        {
            vector<int> fall;
            for (int j=n; j>0; j--)
            {
                if (a[j][i])
                {
                    fall.push_back(a[j][i]);
                }
                a[j][i]=0;
            }
            for (int j=0; j<fall.size(); j++)
            {
                a[n-j][i]=fall[j];
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            fout << a[i][j];
        }
        fout << endl;
    }
    return 0;
}
