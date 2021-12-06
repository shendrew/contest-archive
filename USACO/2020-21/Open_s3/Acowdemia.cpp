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
long long n, k, l;
long long a[100000];

int main()
{
    cin >> n >> k >> l;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());

    int low=0, high=n, mid;
    while (low!=high)
    {
        mid=(low+high+1)/2;

        long long ind=0, cite=0, maxCite=0;
        while (ind<mid)
        {
            if (a[ind] >= mid)
            {
                ind++;
                continue;
            }
            cite+=mid-a[ind];
            maxCite=max(maxCite, mid-a[ind]);
            ind++;
        }

        if (k*l >= cite && k>=maxCite)
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
4 4 1
1 100 1 1

4 1 4
1 100 1 1
*/