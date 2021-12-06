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
int t, n, k;
int dp[1001][1001];

int solve(int ni, int ki)
{
    if (ki==0)
    {
        return 0;
    }
    if (ni==0)
    {
        return 1;
    }
    if (dp[ni][ki])
    {
        return dp[ni][ki];
    }
    int ans=(solve(ni-1, ki)+solve(n-ni, ki-1))%1000000007;
    dp[ni][ki]=ans;
    return dp[ni][ki];
}

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }

    return 0;
}

/*
4
2 3
2 2
3 1
1 3
*/