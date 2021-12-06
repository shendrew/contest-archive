#include <iostream>
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
int n, d;
string str;
int dp[100];

int main()
{
    cin >> n >> d >> str;
    memset(dp, -1, sizeof(dp));
    dp[0]=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (dp[j]!=-1)
            {
                for (int k=1; k<=d; k++)
                {
                    if (str[j+k]-'0' && dp[j+k]==-1)
                    {
                        dp[j+k]=dp[j]+1;
                    }
                }
            }
        }
        if (dp[n-1]!=-1)
        {
            break;
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}

/*
12 3
101111100101
*/