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

int findNum(int n, int exp, int dig)
{
    while (to_string(n).size()<dig)
    {
        n*=exp;
    }
    return n;
}

int main()
{
    cin >> t;
    while (t--)
    {
        int a, b, c, na, nb, nc;
        cin >> a >> b >> c;

        nc=findNum(1, 2, c);
        na=findNum(nc, 3, a);
        nb=findNum(nc, 5, b);
        cout << na << " " << nb << endl;
    }

    return 0;
}

/*
4
2 3 1
2 2 2
6 6 2
1 1 1
*/