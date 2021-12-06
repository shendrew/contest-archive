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
#define mod 1000000007
int n;
long long dp[10000001];

int main()
{
    cin >> n;

    dp[0]=1;
    for (int i=1; i<=n; i++)
    {
        if (i%2)
        {
            dp[i]=((dp[i-1]*3)-3)%mod;
        }
        else
        {
            dp[i]=((dp[i-1]*3)+3)%mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

/*
4
*/