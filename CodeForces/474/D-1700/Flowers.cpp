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
int t, k, high;
pair<int, int> a[100000];
long long prefix[100001];
map<int, long long> dp;

long long solve(int n)
{
    if (n<0)
    {
        return 0;
    }
    if (n<=1)
    {
        n=1;
    }
    if (!dp[n])
    {
        dp[n]=(solve(n-1)+solve(n-k))%1000000007;
    }
    return dp[n];
}

int main()
{
    cin >> t >> k;

    dp[1]=1;
    if (k==1)
    {
        dp[1]=2;
    }

    for (int i=0; i<t; i++)
    {
        cin >> a[i].f >> a[i].s;
        high=max(high, a[i].s);
    }

    solve(high);

    for (int i=1; i<=high; i++)
    {
        prefix[i]=(prefix[i-1]+dp[i])%1000000007;
    }

    for (int i=0; i<t; i++)
    {
        cout << (prefix[a[i].s]-prefix[a[i].f-1])%1000000007 << endl;
    }

    return 0;
}
/*
3 2
1 3
2 3
4 4
*/