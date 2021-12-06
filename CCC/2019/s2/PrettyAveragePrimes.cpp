#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int t, ansA, ansB;
map<int,bool> dp;

bool isPrime(int n)
{
    if (dp.count(n)) return dp[n];
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            dp[n]=false;
            return false;
        }
    }
    dp[n]=true;
    return true;
}

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        n*=2;
        for (int j=2; j<=n-2; j++)
        {
            if (isPrime(j) && isPrime(n-j))
            {
                ansA=j, ansB=n-j;
                break;
            }
        }

        cout << ansA << " " << ansB << endl;
    }
    return 0;
}

/*
4
8
4
7
21
*/
