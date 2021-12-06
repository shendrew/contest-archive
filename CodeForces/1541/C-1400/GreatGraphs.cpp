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
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector<long long> v(n+1);
        for (int i=1; i<=n; i++)
        {
            scanf("%d", &v[i]);
        }
        long long int ans=0;
        if (n<3)
        {
            printf("%lld\n", ans);
        }
        else
        {
            sort(v.begin(), v.end());
            vector<long long> prefix(n+1);
            for (int i=1; i<=n; i++)
            {
                prefix[i]=prefix[i-1]+v[i];
            }
            for (int i=1; i<=n-2; i++)
            {
                ans+=prefix[n]-prefix[i+1]-v[i]*(n-(i+1));
            }
            printf("%lld\n", -ans);
        }
    }

    return 0;
}

/*
3
3
0 2 3
2
0 1000000000
1
0

1
5
0 8 7 3 2

1
4
0 100000000 200000000 300000000
*/