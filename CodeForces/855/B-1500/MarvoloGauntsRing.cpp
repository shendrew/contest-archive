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
long long n, p, q, r;
long long a[100001];
long long dp[3][100001];

int main()
{
    cin >> n >> p >> q >> r;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    dp[0][0]=p*a[0];
    for (int i=1; i<n; i++)
    {
        dp[0][i]=max(dp[0][i-1], a[i]*p);
    }

    dp[1][0]=(p+q)*a[0];
    for (int i=1; i<n; i++)
    {
        dp[1][i]=max(dp[1][i-1], dp[0][i]+a[i]*q);
    }

    dp[2][0]=(p+q+r)*a[0];
    for (int i=1; i<n; i++)
    {
        dp[2][i]=max(dp[2][i-1], dp[1][i]+a[i]*r);
    }

    cout << dp[2][n-1] << endl;

    return 0;
}

/*
5 1 2 -3
-1 -2 -3 -4 -5

3 1 1 1
-1 -2 -3
*/