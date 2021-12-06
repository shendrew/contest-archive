#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

#define f first
#define s second
int n;
int a[2000];
long long dp[2000][2000];

long long solve(int l, int r)
{
    if (l==r)
    {
        return 0;
    }
    if (dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    dp[l][r]=a[r]-a[l]+min(solve(l+1, r), solve(l, r-1));
    return dp[l][r];
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);

    memset(dp, -1, sizeof(dp));
    cout << solve(0, n-1) << endl;

    return 0;
}

/*
6
1 6 3 3 6 3
*/