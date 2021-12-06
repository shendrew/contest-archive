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
#define ll long long
int t;

int main()
{
    cin >> t;
    while (t--)
    {
        long long n, x, t;
        cin >> n >> x >> t;
        long long m=min(n-1, t/x);
        cout << m*(n-m-1)+m*(m+1)/2 << endl;
    }

    return 0;
}

/*
4
4 2 5
3 1 2
3 3 10
2000000000 1 2000000000
*/