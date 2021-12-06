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
int n, k, total, best;
int a[100001], t[100001], prefix[100001];

int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++)
    {
        cin >> t[i];
    }

    for (int i=1; i<=n; i++)
    {
        prefix[i]=prefix[i-1];
        if (t[i])
        {
            total+=a[i];
        }
        else
        {
            prefix[i]+=a[i];
        }
    }

    for (int i=1; i<=n-k+1; i++)
    {
        best=max(best, prefix[i+k-1]-prefix[i-1]);
    }

    cout << total+best << endl;

    return 0;
}

/*
6 3
1 3 5 2 5 4
1 1 0 1 0 0
*/