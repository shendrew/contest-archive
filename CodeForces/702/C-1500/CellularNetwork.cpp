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
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    vector<int> city(n), tower(m);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &city[i]);
    }

    for (int i=0; i<m; i++)
    {
        scanf("%d", &tower[i]);
    }

    long long low=0, high=2000000001, mid=(low+high-1)/2;
    while (low!=high)
    {
        mid=(low+high-1)/2;
        int j=0;
        for (int i=0; i<m; i++)
        {
            if (city[j]<tower[i]-mid)
            {
                break;
            }
            while (tower[i]-mid<=city[j] && city[j]<=tower[i]+mid && j<n)
            {
                j++;
            }
        }

        if (j==n)
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    printf("%lld\n", mid);

    return 0;
}

/*
3 2
-2 2 4
-3 0
*/