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
long long a[300000], b[300000], shot[300000];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        long long total=0;
        for (int i=0; i<n; i++)
        {
            scanf("%lld%lld", &a[i], &b[i]);
        }
        for (int i=0; i<n; i++)
        {
            shot[(i+1)%n]=max((long long) 0, a[(i+1)%n]-b[i]);
            total+=shot[(i+1)%n];
        }
        long long ans=total-shot[0]+a[0];
        for (int i=0; i<n; i++)
        {
            ans=min(ans, total-shot[i]+a[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}

/*
1
3
7 15
2 14
5 3
*/