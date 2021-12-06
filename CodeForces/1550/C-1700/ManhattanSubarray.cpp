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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++)
        {
            int a;
            cin >> v[i];
        }

        auto good = [&](int l, int r) {
            for (int i=l; i<=r; i++)
            {
                for (int j=i+1; j<=r; j++)
                {
                    for (int k=j+1; k<=r; k++)
                    {
                        if (v[i]<=v[j] && v[j]<=v[k])
                        {
                            return false;
                        }
                        if (v[i]>=v[j] && v[j]>=v[k])
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        };

        int ans=0;
        for (int i=0; i<n; i++)
        {
            int j=i;
            while (j<n && good(i, j))
            {
                j++;
            }
            j--;
            ans += j-i+1;
        }
        cout << ans << endl;
    }

    return 0;
}

/*
3
4
2 4 1 3
5
6 9 1 9 6
2
13 37
*/