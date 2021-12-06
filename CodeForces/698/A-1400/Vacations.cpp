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
int a[100];
int dp[100][3];

int solve(int cur, int pre)
{
    if (cur==n)
    {
        return 0;
    }
    if (dp[cur][pre]!=-1)
    {
        return dp[cur][pre];
    }
    int contest=1, sport=1;
    if ((a[cur]==3 || a[cur]==1) && pre!=1)     
    {
        contest=solve(cur+1, 1);
    }
    else
    {
        contest=solve(cur+1, 0)+1;
    }
    if ((a[cur]==3 || a[cur]==2) && pre!=2)
    {
        sport=solve(cur+1, 2);
    }
    else
    {
        sport=solve(cur+1, 0)+1;
    }
    return dp[cur][pre]=min(contest, sport);
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;

    return 0;
}

/*
4
1 3 2 0
*/