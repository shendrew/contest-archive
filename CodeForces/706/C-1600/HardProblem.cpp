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
string a[100001];
int c[100001];
long long dp[100001][2];
long long ans;

bool compare(string x, string y)
{
    if (x <= y)
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> c[i];
    }
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    dp[0][0]=0, dp[0][1]=c[0];
    for (int i=1; i<n; i++)
    {
        dp[i][0]=dp[i][1]=pow(10, 16);
        string rpre=a[i-1], rcur=a[i];
        reverse(rpre.begin(), rpre.end()), reverse(rcur.begin(), rcur.end());
        if (compare(a[i-1], a[i]))
        {
            dp[i][0]=min(dp[i][0], dp[i-1][0]);
        }
        if (compare(rpre, a[i]))
        {
            dp[i][0]=min(dp[i][0], dp[i-1][1]);
        }
        if (compare(a[i-1], rcur))
        {
            dp[i][1]=min(dp[i][1], dp[i-1][0]+c[i]);
        }
        if (compare(rpre, rcur))
        {
            dp[i][1]=min(dp[i][1], dp[i-1][1]+c[i]);
        }
    }
    
    ans=min(dp[n-1][0], dp[n-1][1]);
    if (ans==pow(10, 16))
    {
        ans=-1;
    }
    cout << ans << endl;

    return 0;
}

/*
2
1 2
ba
ac
*/