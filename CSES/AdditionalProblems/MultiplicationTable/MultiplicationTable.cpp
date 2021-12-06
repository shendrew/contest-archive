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

long long n;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    long long low=1, high=n*n, mid=low+(high-low)/2;
    while (low<high)
    {
        mid=low+(high-low)/2;
        long long cnt=0;
        for (int i=1; i<=n; i++)
        {
            cnt+=min(n, mid/i);
        }
        if (cnt>=(n*n+1)/2)
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
3
*/
