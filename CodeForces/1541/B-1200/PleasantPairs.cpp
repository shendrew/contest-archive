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
using namespace std;

#define f first
#define s second
#define ll long long
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<long long> v(n+1);
        vector<vector<int>> test(n+1);
        for (int i=1; i<=n; i++)
        {
            scanf("%lld", &v[i]);
        }

        long long ans=0;
        for (int i=1; i<=n; i++)
        {
            if (v[i]>i+n)
            {
                continue;
            }
            for (int j=1; j<=n+i; j++)
            {
                if (j*v[i]-i>n)
                {
                    break;
                }
                if (j*v[i]-i>i)
                {
                    test[i].push_back(j*v[i]-i);
                }
            }
            for (auto &j: test[i])
            {
                if (v[i]*v[j]==i+j)
                {
                    ans++;
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}

/*
3
2
3 1
3
6 1 5
5
3 1 5 9 2
*/