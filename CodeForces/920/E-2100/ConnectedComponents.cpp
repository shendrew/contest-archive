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

#define f first
#define s second
#define ll long long

int n, m, cnt;
int visited[200005];
multiset<int> ans;

void dfs(int node)
{
    
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    set<pair<int, int>> noEdge;
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        noEdge.insert({a, b});
        noEdge.insert({b, a});
    }

    set<int> test;
    for (int i=1; i<=n; i++)
    {
        test.insert(i);
    }

    for (int i=1; i<=n; i++)
    {
        if (!visited[i])
        {
            cnt=0;
            queue<int> que;
            que.push(i);

            visited[i]=1;
            test.erase(i);
            while (que.size())
            {
                int cur=que.front();
                que.pop();
                cnt++;
                vector<int> rmv;
                for (auto &j: test)
                {
                    if (!visited[j] && noEdge.count({cur, j})==0)
                    {
                        que.push(j);
                        visited[j]=1;
                        rmv.push_back(j);
                    }
                }
                for (auto &i: rmv)
                {
                    test.erase(i);
                }
            }
            ans.insert(cnt);
        }
    }

    cout << ans.size() << endl;
    for (auto &i: ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
5 5
1 2
3 4
3 2
4 2
2 5
*/