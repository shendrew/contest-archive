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
        cin >> n;
        vector<vector<int>> v(n);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<5; j++)
            {
                int ri;
                cin >> ri;
                v[i].push_back(ri);
            }
        }
        
        auto test = [&](int vi, int vj)
        {
            int winI=0, winJ=0;
            for (int i=0; i<5; i++)
            {
                if (v[vi][i]<v[vj][i])
                {
                    winI++;
                }
                else
                {
                    winJ++;
                }
            }
            return winI>=3;
        };

        int winner=0;
        for (int i=1; i<n; i++)
        {
            if (test(i, winner))
            {
                winner=i;
            }
        }
        bool possible=true;
        for (int i=0; i<n; i++)
        {
            if (winner!=i)
            {
                possible=(possible&&test(winner, i));
            }
        }
        if (possible)
        {
            cout << winner+1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}

/*
4
1
50000 1 50000 50000 50000
3
10 10 20 30 30
20 20 30 10 10
30 30 10 20 20
3
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
6
9 5 3 7 1
7 4 1 6 8
5 6 7 3 2
6 7 8 8 6
4 2 2 4 5
8 3 6 9 4
*/