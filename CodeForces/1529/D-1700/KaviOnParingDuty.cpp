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
#define mod 998244353;

int n;
int dp[1000005];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j<=n; j+=i)
        {
            dp[j]++;
        }
        dp[i]+=(2*dp[i-1])%mod;
    }
    int ans=(dp[n]+998244353-dp[n-1])%mod;

    cout << ans << endl;

    return 0;
}

/*
100

5
1: 1
2: 1 + 2 = 3
3: 4 + 2 = 6
4: 10 + 3  = 13


1
4
10
23
48
*/