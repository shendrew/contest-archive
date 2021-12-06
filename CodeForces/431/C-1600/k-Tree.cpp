#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;

#define f first
#define s second
int n, k, d;
long long dp[101][2];

long long solve(int cur, int ok)
{
    if (cur==0)
    {
        return ok;
    }
    else if (cur<0)
    {
        return 0;
    }
    if (dp[cur][ok] != -1)
    {
        return dp[cur][ok];
    }
    long long ans=0;
    for (int i=1; i<=k; i++)
    {
        if (i>=d)
        {
            ans=(ans+solve(cur-i, 1))%1000000007;
        }
        else
        {
            ans=(ans+solve(cur-i, ok))%1000000007;
        }
    }
    dp[cur][ok]=ans%1000000007;
    return dp[cur][ok];
}

int main()
{
    cin >> n >> k >> d;

    memset(dp, -1, sizeof(dp));

    cout << solve(n, 0) << endl;

    return 0;
}

/*
3 3 2

3 3 3

4 3 2

4 5 2
*/