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
        int n;
        cin >> n;
        map<int, int> visit;
        for (int i=0; i<n; i++)
        {
            int a;
            cin >> a;
            visit[(n+(a+i)%n)%n]=true;
        }
        bool possible=true;
        for (int i=0; i<n; i++)
        {
            possible=(possible && visit[i]);
        }

        if (possible)
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
6
1
14
2
1 -1
4
5 5 5 1
3
3 2 1
2
0 1
5
-239 -2 -100 -3 -11
*/