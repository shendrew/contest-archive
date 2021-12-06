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
int n, k;
int a[200001];

int main()
{
    cin >> n >> k;
    int low=1, high=0;

    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        high=max(high, a[i]);
    }

    int mid=(low+high+1)/2;

    while (low!=high)
    {
        int best=0;
        mid=(low+high+1)/2;
        vector<int> prefix, mini;
        prefix.push_back(0);
        mini.push_back(0);

        for (int i=1; i<=n; i++)
        {
            prefix.push_back(prefix[i-1]);
            if (a[i]>=mid)
            {
                prefix[i]++;
            }
            else
            {
                prefix[i]--;
            }
            mini.push_back(min(mini[i-1], prefix[i]));
        }
        for (int i=k; i<=n; i++)
        {
            best=max(best, prefix[i]-mini[i-k]);
        }
        if (best)
        {
            low=mid;
        }
        else
        {
            high=--mid;
        }
    }

    cout << mid << endl;

    return 0;
}

/*
5 3
1 2 3 2 1
*/