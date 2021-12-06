#include <iostream>
#include <fstream>
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
#include <iomanip>
using namespace std;

#define f first
#define s second
#define ll long long

int n, k;
int dp[251][251][251];

int solve(int pie, int people, int pre)
{
    int ret=0;
    if (people==1)
    {
        if (pie>=pre)
        {
            return 1;
        }
        return 0;
    }
    if (dp[pie][people][pre]!=-1)
    {
        return dp[pie][people][pre];
    }
    for (int i=pre; i<=pie/people; i++)
    {
        ret+=solve(pie-i, people-1, i);
    }

    return dp[pie][people][pre]=ret;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));

    cout << solve(n, k, 1) << endl;

    return 0;
}

/*
8
4
*/