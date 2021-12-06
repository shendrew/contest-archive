#include <iostream>
#include <fstream>
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
#define ll long long
int t;

int main()
{
    cin >> t;
    while (t--)
    {
        double h, c, tar;
        cin >> h >> c >> tar;
        double a=(h+c)/2;
        if (tar==h)
        {
            cout << 1 << endl;
        }
        else if (tar<=a)
        {
            cout << 2 << endl;
        }
        else
        {
            int r=round((h-a)/(tar-a));
            if (r%2)
            {
                cout << r << endl;
            }
            else
            {
                if (abs(tar-(a+(h-a)/(r-1))) <= abs(tar-(a+(h-a)/(r+1))))
                {
                    cout << r-1 << endl;
                }
                else
                {
                    cout << r+1 << endl;
                }
            }
        }
    }

    return 0;
}

/*
3
30 10 20
41 15 30
18 13 18
*/