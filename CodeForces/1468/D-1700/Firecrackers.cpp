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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<int> v(m);
        for (int i=0; i<m; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int steps;
        if (a<b)
            steps=b-1;
        else
            steps=n-b;

        int low=0, high=m;
        while (low<high)
        {
            int mid=(low+high+1)/2;
            bool possible=true;
            
            for (int i=0; i<mid; i++)
            {
                if (v[i]+mid-i>steps)
                {
                    possible=false;
                    break;
                }
            }

            if (mid<abs(a-b) && possible)
            {
                low=mid;
            }
            else
            {
                high=--mid;
            }
        }

        cout << low << endl;
    }

    return 0;
}

/*
3
7 2 3 6
1 4
7 2 3 6
5 1
7 2 3 6
4 4

bombs: b-a-1
steps: b-1 or n-b
*/