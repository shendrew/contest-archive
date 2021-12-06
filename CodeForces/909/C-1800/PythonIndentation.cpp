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
#define mod 1000000007;
int n, ans;
int a[5001];
int dp[5002][5002];

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        char ai;
        cin >> ai;
        if (ai=='f')
        {
            a[i]=1;
        }
    }

    dp[0][0]=1;

    for (int i=1; i<=n; i++)
    {
        int sum=0;
        for (int j=n-1; j>=0; j--)
        {
            sum=(sum+dp[i-1][j])%mod;
            if (a[i-1])
            {
                dp[i][j+1]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=(dp[i][j]+sum)%mod;
            }
        }
    }

    for (int i=0; i<=n; i++)
    {
        ans=(ans+dp[n][i])%mod;
    }

    cout << ans << endl;

    return 0;
}

/*
4
f
s
f
s
*/