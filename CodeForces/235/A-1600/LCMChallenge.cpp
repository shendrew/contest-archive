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
long long n;

int main()
{
    cin >> n;

    if (n>2)
    {
        if (n%2)
        {
            cout << n*(n-1)*(n-2) << endl;
        }
        else if (n%3)
        {
            cout << n*(n-1)*(n-3) << endl;
        }
        else
        {
            cout << (n-1)*(n-2)*(n-3) << endl;
        }
    }
    else
    {
        cout << n << endl;
    }

    return 0;
}

/*
9
*/