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
#define ll long long
int t;

int main()
{
    cin >> t;
    while (t--)
    {
        int n, k, z;
        cin >> n >> k >> z;
        vector<long long> v(n+1), sum(n+1);
        for (int i=1; i<=n; i++)
        {
            cin >> v[i];
            sum[i]=sum[i-1]+v[i];
        }

        long long ans=sum[k+1];
        for (int i=0; i<=z; i++)
        {
            if (k-2*i+1<=0)
            {
                break;
            }
            long long mx=0;
            for (int j=1; j<=k-2*i+1; j++)
            {
                if (j>n-1)
                {
                    break;
                }
                mx=max(mx, v[j]+v[j+1]);
            }
            ans=max(ans, sum[k-2*i+1]+mx*i);
        }

        cout << ans << endl;
    }

    return 0;
}

/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9
*/