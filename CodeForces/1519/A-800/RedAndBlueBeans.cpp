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

int main()
{
    cin >> t;
    while (t--)
    {
        double r, b, d;
        cin >> r >> b >> d;
        if ((ceil(max(r,b)/min(r,b)))-1<=d)
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
4
1 1 0
2 7 3
6 1 4
5 4 0
*/