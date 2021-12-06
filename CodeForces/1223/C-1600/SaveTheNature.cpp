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
        int n, x, y, a, b;
        long long k;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++)
        {
            cin >> v[i];
        }
        cin >> x >> a >> y >> b >> k;

        sort(v.begin(), v.end(), greater<int>());
        int low=0, high=n, mid;
        while (low<high)
        {
            mid=low+(high-low)/2;
            vector<long long> donate;
            for (int i=0; i<=mid; i++)
            {
                int di=0;
                if ((i+1)%a==0)
                {
                    di+=x;
                }
                if ((i+1)%b==0)
                {
                    di+=y;
                }
                if (di)
                {
                    donate.push_back(di);
                }
            }
            sort(donate.begin(), donate.end(), greater<int>());

            long long sum=0;
            for (int i=0; i<donate.size(); i++)
            {
                sum+=donate[i]*v[i]/100;
            }

            if (sum>=k)
            {
                high=mid;
            }
            else
            {
                low=++mid;
            }
        }

        if (mid==n)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << mid+1 << endl;
        }
    }

    return 0;
}

/*
4
1
100
50 1
49 1
100
8
100 200 100 200 100 200 100 100
10 2
15 3
107
3
1000000000 1000000000 1000000000
50 1
50 1
3000000000
5
200 100 100 100 100
69 5
31 2
90
*/