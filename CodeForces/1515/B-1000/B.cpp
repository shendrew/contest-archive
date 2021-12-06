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

bool check(int n)
{
    int root=sqrt(n/2);
    int half=sqrt(n/4);
    return ((root*root==double(n)/2) || (half*half==double(n)/4));
}

int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (check(n) && n>1 && !(n%2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*
3
2
4
6
*/