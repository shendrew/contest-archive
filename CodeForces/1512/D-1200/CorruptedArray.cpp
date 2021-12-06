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
        v.resize(n+2);
        for (int i=0; i<n+2; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        long long sum=0;
        for (int i=0; i<n; i++)
        {
            sum+=v[i];
        }
        if (sum==v[n])
        {
            for (int i=0; i<n; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        else
        {
            int extra=0;
            sum+=v[n];
            for (int i=0; i<n+1; i++)
            {
                if (sum-v[i]==v[n+1])
                {
                    extra=i+1;
                    break;
                }
            }
            if (extra)
            {
                for (int i=0; i<n+1; i++)
                {
                    if (i!=extra-1)
                    {
                        cout << v[i] << " ";
                    }
                }
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}

/*
4
3
2 3 7 12 2
4
9 1 7 1 6 5
5
18 2 2 3 2 9 2
3
2 6 9 2 1
*/