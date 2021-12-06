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
#include <iomanip>
using namespace std;

#define f first
#define s second
#define ll long long

int n, t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    vector<long long> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    long long low=1, high=1e18, mid;
    while (low<high)
    {
        mid=low+(high-low)/2;
        long long sum=0;
        for (int i=0; i<n; i++)
        {
            if (sum>=t)
            {
                break;
            }
            sum+=mid/v[i];
        }
        if (sum>=t)
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    cout << mid << endl;

    return 0;
}

/*
3 7
3 2 5
*/