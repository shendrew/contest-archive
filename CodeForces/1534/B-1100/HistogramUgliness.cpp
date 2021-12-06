#include <iostream>
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
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> v={0};
        for (int i=0; i<n; i++)
        {
            int a;
            scanf("%d", &a);
            v.push_back(a);
        }
        v.push_back(0);
        
        long long ans=0;
        for (int i=1; i<=n; i++)
        {
            ans+=v[i]-min(v[i], max(v[i-1], v[i+1]));
            v[i]=min(v[i], max(v[i-1], v[i+1]));
        }
        for (int i=1; i<=n; i++)
        {
            ans+=max(0, v[i]-v[i-1])+max(0, v[i]-v[i+1]);
        }

        printf("%llu\n", ans);
    }

    return 0;
}

/*
2
4
4 8 9 6
6
2 1 7 4 0 0
*/