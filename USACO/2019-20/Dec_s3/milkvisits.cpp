#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int n, m, num;
string milk;
vector<int> a[100001];
int group[100001];

int main()
{
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");

    fin >> n >> m >> milk;
    for (int i=0; i<n-1; i++)
    {
        int x, y;
        fin >> x >> y;
        a[x].push_back(y), a[y].push_back(x);
    }
    for (int i=1; i<=n; i++)
    {
        num++;
        if (!group[i])
        {
            queue<int> que;
            que.push(i);
            while (que.size())
            {
                int cur=que.front();
                que.pop();
                group[cur]=num;
                for (int j=0; j<a[cur].size(); j++)
                {
                    if (!group[a[cur][j]] && milk[cur-1]==milk[a[cur][j]-1])
                    {
                        que.push(a[cur][j]);
                    }
                }
            }
        }
    }
    for (int i=0; i<m; i++)
    {
        int start, finish;
        char taste;
        fin >> start >> finish >> taste;
        if (milk[start-1]==taste || group[start]!=group[finish])
            fout << 1;
        else
            fout << 0;
    }
    return 0;
}
