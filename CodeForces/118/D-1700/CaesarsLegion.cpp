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
#define mod 100000000;
int n1, n2, k1, k2;
int dp[101][101][11][11];

int solve(int foot, int horse, int cf, int ch)
{
    if (foot+horse==0)
    {
        return 1;
    }

    if (dp[foot][horse][cf][ch]!=-1)
    {
        return dp[foot][horse][cf][ch];
    }

    int x=0, y=0;
    if (foot>0 && cf<k1)
    {
        x=solve(foot-1, horse, cf+1, 0);
    }
    if (horse>0 && ch<k2)
    {
        y=solve(foot, horse-1, 0, ch+1);
    }

    return dp[foot][horse][cf][ch] = (x+y)%mod;
}

int main()
{
    cin >> n1 >> n2 >> k1 >> k2;

    memset(dp, -1, sizeof(dp));
    cout << solve(n1, n2, 0, 0) << endl;

    return 0;
}

/*
2 3 1 2
*/