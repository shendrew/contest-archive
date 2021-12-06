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
int n;

bool isPrime(int n)
{
    int sq=sqrt(n);
    for (int i=2; i<=sq; i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;

    if (isPrime(n))
    {
        cout << 1 << endl << n << endl;
    }
    else
    {
        cout << 3 << endl;
        n-=3;
        for (int i=2; i<=n/2; i++)
        {
            if (isPrime(i) && isPrime(n-i))
            {
                cout << 3 << " " << i << " " << n-i << endl;
                break;
            }
        }
    }

    return 0;
}

/*
27
*/