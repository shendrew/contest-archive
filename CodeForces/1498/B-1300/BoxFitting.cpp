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

    for (int i=0; i<t; i++)
    {
        int n, w;
        cin >> n >> w;
        vector<int> v;
        map<int,int> m;
        for (int j=0; j<n; j++)
        {
            int k;
            cin >> k;
            if (!m[k])
            {
                v.push_back(k);
            }
            m[k]++;
        }
        
        sort(v.begin(), v.end(), greater<int>());
        int done=0, ans=0;
        while (done<n)
        {
            int cur=0, sum=0;

            while (sum<w && done<n && cur<v.size())
            {
                if (sum+v[cur]<=w && m[v[cur]])
                {
                    int take=min(m[v[cur]], (w-sum)/v[cur]);
                    m[v[cur]]-=take;
                    sum+=v[cur]*take;
                    done+=take;
                }
                else
                {
                    cur++;
                }
            }
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
/*
2
5 16
1 2 8 4 8
6 10
2 8 8 2 2 8

1
5 10
1 2 4 4 8
*/