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
int t;

long long solve(long long n)
{
    bool good=true;
    long long m=n;
    while (m!=0)
    {
        long long r=m%10;
        m/=10;
        if (r && n%r)
        {
            good=false;
            break;
        }
    }
    return good;
}

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        long long n;
        cin >> n;
        while (solve(n)==0)
        {
            n++;
        }
        cout << n << endl;
    }

    return 0;
}

/*
4
1
282
1234567890
1000000000000000000
*/