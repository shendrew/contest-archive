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

int before(long long p, int n, int range)
{
    if (p/n*n <= p && p <= p/n*n+range-1 && p/n*n)
    {
        return p-(p/n*n)+1;
    }
    return 0;
}

int main()
{
    cin >> t;
    while (t--)
    {
        long long a, b, q, m;
        cin >> a >> b >> q;
        m=lcm(a, b);
        for (int i=0; i<q; i++)
        {
            long long l, r, ans=0;
            cin >> l >> r;
            ans=max((long long) 0, r-max(l, max(a, b))+1);

            ans-=max((long long) 0, (r-max(a, b))/m*max(a, b));
            ans-=before(r, m, max(a, b));

            ans+=max((long long) 0, (l-1-max(a, b))/m*max(a, b));
            ans+=before(l-1, m, max(a, b));

            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
2
4 6 5
1 1
1 3
1 5
1 7
1 9
7 10 2
7 8
100 200
*/