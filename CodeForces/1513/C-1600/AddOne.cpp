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
int t;
int dp[200001];

int main()
{
    for (int i=0; i<=9; i++)
    {
        dp[i]=1;
    }
    for (int i=10; i<=200001; i++)
    {
        dp[i]=(dp[i-9]+dp[i-10])%1000000007;
    }

    cin >> t;
    while (t--)
    {
        int n, m;
        long long ans=0;
        cin >> n >> m;
        while (n>0)
        {
            ans=(ans+dp[n%10+m])%1000000007;
            n/=10;
        }
        cout << ans << endl;
    }

    return 0;
}

/*
5
1912 1
5 6
999 1
88 2
12 100
*/