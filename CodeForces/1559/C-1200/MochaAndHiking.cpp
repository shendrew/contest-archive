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
        cin >> n;
        vector<int> v(n+1);
        for (int i=1; i<=n; i++)
        {
            cin >> v[i];
        }
        v.push_back(1);

        int ind=-1;
        for (int i=0; i<=n; i++)
        {
            if (v[i]==0 && v[i+1]==1)
            {
                ind=i;
                break;
            }
        }

        if (ind==0)
        {
            cout << n+1 << " ";
        }
        for (int i=0; i<n; i++)
        {
            cout << i+1 << " ";
            if (i+1==ind)
            {
                cout << n+1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

/*
2
3
0 1 0
3
1 1 0
*/