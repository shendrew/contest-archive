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
        int n;
        cin >> n;
        map<int, vector<long long>> mp, prefix;
        vector<int> u(n);
        set<int> uni;
        for (int i=0; i<n; i++)
        {
            cin >> u[i];
            uni.insert(u[i]);
        }
        for (int i=0; i<n; i++)
        {
            int skill;
            cin >> skill;
            mp[u[i]].push_back(skill);
        }

        for (auto &i: uni)
        {
            sort(mp[i].begin(), mp[i].end(), greater<int>());
            prefix[i].push_back(0);
            for (int j=0; j<mp[i].size(); j++)
            {
                prefix[i].push_back(prefix[i][j]+mp[i][j]);
            }
        }

        map<int, long long> ans;
        for (auto &i: uni)
        {
            for (int k=1; k<=n; k++)
            {
                long long plus=prefix[i][(mp[i].size()/k)*k];
                if (!plus)
                {
                    break;
                }
                ans[k]+=plus;
            }
        }

        for (int k=1; k<=n; k++)
        {
            cout << ans[k] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
4
7
1 2 1 2 1 2 1
6 8 3 1 5 1 5
10
1 1 1 2 2 2 2 3 3 3
3435 3014 2241 2233 2893 2102 2286 2175 1961 2567
6
3 3 3 3 3 3
5 9 6 7 9 7
1
1
3083
*/