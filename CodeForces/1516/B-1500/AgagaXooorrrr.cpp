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
        vector<int> v;
        v.resize(n);
        for (int i=0; i<n; i++)
        {
            cin >> v[i];
        }
        int total=0;
        for (int i=0; i<n; i++)
        {
            total=(total^v[i]);
        }
        if (!total)
        {
            cout << "YES" << endl;
        }
        else
        {
            int cur=0, part=0;
            for (int i=0; i<n; i++)
            {
                cur=(cur^v[i]);
                if (cur==total)
                {
                    cur=0;
                    part++;
                }
            }
            if (part>1 && cur==0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}

/*
2
3
0 2 2
4
2 3 1 10
*/