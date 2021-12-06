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
    for (int i=0; i<t; i++)
    {
        int n, maxi=0;
        cin >> n;

        vector<int> a;
        a.resize(n);
        for (int j=0; j<n; j++)
        {
            cin >> a[j];
            maxi=max(maxi, a[j]);
        }

        int inc=0, dec=0, m;
        bool possible=true, increase=false, decrease=false;
        for (int j=1; j<n; j++)
        {
            if (a[j]>=a[j-1])
            {
                if (increase && inc!=a[j]-a[j-1])
                {
                    possible=false;
                    break;
                }
                inc=a[j]-a[j-1];
                increase=true;
            }
            else if (a[j]<a[j-1])
            {
                if (decrease && dec!=a[j-1]-a[j])
                {
                    possible=false;
                    break;
                }
                dec=a[j-1]-a[j];
                decrease=true;
            }
        }

        if (!possible)
        {
            cout << -1 << endl;
        }
        else if (increase && decrease)
        {
            m=inc+dec;
            if (m>maxi)
            {
                cout << m << " " << inc << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}
/*
6
6
1 9 17 6 14 3
3
4 2 2
3
7 3 4
3
2 2 4
5
0 1000000000 0 1000000000 0
2
1 1
*/