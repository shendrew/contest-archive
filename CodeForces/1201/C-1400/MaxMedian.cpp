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

long long n, k;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    int low=1, high=2e9, mid;
    while (low!=high)
    {
        mid=low+(high-low+1)/2;
        long long cost=0;
        for (int i=0; i<(n+1)/2; i++)
        {
            cost+=max(0, mid-v[i]);
        }
        if (cost<=k)
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
7 7
4 1 2 4 3 4 4
*/