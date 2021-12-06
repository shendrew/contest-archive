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
int t;

int main()
{
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n), visit(n), ans(n);
        vector<pair<int, pair<int, int>>> all;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                int b;
                cin >> b;
                v[i].push_back(b);
                visit[i].push_back(0);
                ans[i].push_back(-1);
            }
            for (int j=0; j<m; j++)
            {
                all.push_back({v[i][j], {i, j}});
            }
        }

        sort(all.begin(), all.end());

        for (int i=0; i<m; i++)
        {
            ans[all[i].s.f][i]=all[i].s.s;
            visit[all[i].s.f][all[i].s.s]=1;
        }

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (ans[i][j]==-1)
                {
                    int ind=0;
                    while (visit[i][ind])
                    {
                        ind++;
                    }
                    ans[i][j]=ind;
                    visit[i][ind]=true;
                }
                cout << v[i][ans[i][j]] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

/*
2
2 3
2 3 4
1 3 5
3 2
2 3
4 1
3 5
*/