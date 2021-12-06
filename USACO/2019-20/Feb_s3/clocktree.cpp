#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream fin("clocktree.in");
ofstream fout("clocktree.out");

int n, ans, leaf;
int tree[2501], visited[2501], inStack[2501];
vector<int> path[2501];
vector<int> times;
stack<int> stk;

void dfs()
{
    int done=0, parent, current, j;
    while (n-done>1)
    {
        leaf=0;
        current=stk.top();
        for (j=0; j<path[current].size(); j++)
        {
            if (visited[path[current][j]]==0)
            {
                parent=path[current][j];
                if (inStack[path[current][j]]==0)
                {
                    leaf=path[current][j];
                    break;
                }
            }
        }

        if (leaf==0) // pop current
        {
            leaf=parent;
            times[leaf]=(times[leaf]+12-times[current])%12;
            stk.pop();
            inStack[current]=0, visited[current]=1, done++;
        }
        else // add to stack
        {
            stk.push(leaf);
            inStack[leaf]=1;
        }
        times[leaf]=(times[leaf]+1)%12;
    }
}

int main()
{
    fin >> n;
    int i, j;
    for (i=1; i<=n; i++)
    {
        fin >> tree[i];
    }
    for (i=0; i<n-1; i++)
    {
        int x, y;
        fin >> x >> y;
        path[x].push_back(y),  path[y].push_back(x);
    }

    //dfs
    for (int e=1; e<=n; e++) // 1 to n
    {
        times.clear();
        for (i=0; i<=n; i++)
        {
            times.push_back(tree[i]%12);
        }
        stk.empty();
        stk.push(e);
        inStack[e]=1;

        dfs();

        if (times[leaf]%12==0 || times[leaf]%12==1)
        {
            ans++;
        }
        for (i=1; i<=n; i++)
            visited[i]=0, inStack[i]=0;
    }
    fout << ans;
    return 0;
}
