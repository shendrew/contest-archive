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
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (x2-x1)*(y2-y1)+1 << endl;
    }

    return 0;
}

/*
4
1 1 2 2
1 2 2 4
179 1 179 100000
5 7 5 7
*/