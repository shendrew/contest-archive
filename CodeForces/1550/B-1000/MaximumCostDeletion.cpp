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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int n, a, b;
        string str;
        cin >> n >> a >> b >> str;
        if (b>=0)
        {
            cout << a*n+b*n << endl;
        }
        else
        {
            int pre=str[0], zero=0, one=0;
            if (str[0]=='0')
            {
                zero++;
            }
            else
            {
                one++;
            }
            for (int i=0; i<n; i++)
            {
                if (str[i]!=pre)
                {
                    if (str[i]=='0')
                    {
                        zero++;
                    }
                    else
                    {
                        one++;
                    }
                }
                pre=str[i];
            }
            cout << a*n+b*(min(zero, one)+1) << endl;
        }
    }

    return 0;
}

/*
3
3 2 0
000
5 -2 5
11001
6 1 -4
100111
*/