#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, ans;
set<int> visited, inque;
vector<int> a[100001];

int main()
{
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y), a[y].push_back(x);
    }

    queue<int> que;
    que.push(1);
    inque.insert(1);
    while (que.size())
    {
        int cur=que.front(), cow=1, leaf=0;
        que.pop();
        visited.insert(cur);
        inque.erase(cur);
        for (int i=0; i<a[cur].size(); i++)
        {
            if (visited.count(a[cur][i])==0 && inque.count(a[cur][i])==0)
            {
                que.push(a[cur][i]);
                inque.insert(a[cur][i]);
                leaf++;
            }
        }
        if (leaf)
        {
            ans+=leaf;
            while (cow<=leaf)
            {
                cow*=2;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
4
1 2
1 3
1 4
*/
