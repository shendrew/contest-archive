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

long long sum(long long n)
{
    int ret=0;
    while (n)
    {
        ret+=n%10;
        n/=10;
    }
    return ret;
}

int main()
{
    cin >> t;
    while (t--)
    {
        long long n, og, sm;
        cin >> n >> sm;
        og=n;
        int dig=0;
        while (sum(n)>sm)
        {
            n+=(10-(n/(long long)pow(10, dig))%10)*pow(10,dig);
            dig++;
        }
        cout << n-og << endl;
    }

    return 0;
}

/*
5
2 1
1 1
500 4
217871987498122 10
100000000000000001 1
*/