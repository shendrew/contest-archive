#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m, ans;
int cat[100001], sum[100001], cst[100001];
bool visited[100001];
vector<int> tree[100001];

int main()
{
    cin >> n >> m;
    int i;
    for (i=1; i<=n; i++)
    {
        cin >> cat[i];
    }
    for (i=0; i<n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y), tree[y].push_back(x);
    }
    stack<int> stk;
    stk.push(1);
    visited[1]=true;
    sum[1]=cat[1], cst[1]=cat[1];
    while (stk.size())
    {
        int cur=stk.top();
        stk.pop();
        bool leaf=true;
        for (i=0; i<tree[cur].size(); i++)
        {
            if (!visited[tree[cur][i]])
            {
                leaf=false;
                stk.push(tree[cur][i]);
                visited[tree[cur][i]]=true;
                if (cat[tree[cur][i]])
                    cst[tree[cur][i]]=cst[cur]+cat[tree[cur][i]];
                else
                    cst[tree[cur][i]]=0;
                sum[tree[cur][i]]=max(sum[cur], cst[tree[cur][i]]);
            }
        }
        if (leaf)
        {
            if (sum[cur]<=m)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
