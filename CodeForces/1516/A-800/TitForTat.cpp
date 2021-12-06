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
        int n, k;
        cin >> n >> k;
        vector<int> v;
        v.resize(n);
        for (int i=0; i<n; i++)
        {
            cin >> v[i];
        }
        int ind=0;
        for (int i=0; i<k; i++)
        {
            while (v[ind]<=0 && ind<n-1)
            {
                ind++;
            }
            if (ind>n)
            {
                break;
            }
            v[ind]--;
            v[n-1]++;
        }

        for (auto &i: v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
2
3 1
3 1 4
2 10
1 0
*/