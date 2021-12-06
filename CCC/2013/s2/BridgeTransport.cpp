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

int w, n;

int main()
{
    cin >> w >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    v.push_back(0);

    int total=0, l=0, r=0;
    for (; l<n; l++)
    {
        while (r-l<4 && r<n)
        {
            total+=v[r];
            if (total>w)
            {
                break;
            }
            r++;
        }
        if (total>w)
        {
            break;
        }
        total-=v[l];
    }

    cout << r << endl;

    return 0;
}

/*
100
6
50
30
10
10
40
50
*/