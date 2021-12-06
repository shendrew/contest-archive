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
#include <iomanip>
#include <functional>
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
        int n;
        string str;
        cin >> n >> str;

        int d=0, k=0;
        map<pair<int, int>, int> m;
        for (int i=0; i<n; i++)
        {
            if (str[i]=='D')
                d++;
            else
                k++;

            int g=gcd(d, k);

            m[{d/g, k/g}]++;
            cout << m[{d/g, k/g}] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
5
3
DDK
6
DDDDDD
4
DKDK
1
D
9
DKDKDDDDK
*/