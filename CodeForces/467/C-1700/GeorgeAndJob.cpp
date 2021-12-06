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
using namespace std;

#define f first
#define s second
#define ll long long
int n, m, k;
long long prefix[5001];
long long dp[5001][5001];
long long ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
    {
        long long ai;
        cin >> ai;
        prefix[i]=prefix[i-1]+ai;
    }

    for (int i=1; i<=k; i++)
    {
        for (int j=m; j<=n; j++)
        {
            if ((m*i)<=j)
            {
                dp[i][j]=max(dp[i][j-1], dp[i-1][j-m]+prefix[j]-prefix[j-m]);
            }
        }
    }

    cout << dp[k][n] << endl;

    return 0;
}

/*
5 2 1
1 2 3 4 5
*/