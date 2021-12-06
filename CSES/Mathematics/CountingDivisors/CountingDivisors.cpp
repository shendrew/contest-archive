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
int vis[1000006];

int main()
{
    vector<int> prime;
    for (int i=2; i<1000000; i++)
    {
        if (!vis[i])
        {
            for (int j=i; j<=1000000; j+=i)
            {
                vis[j]=i;
            }
        }
    }

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int ans=1;
        while (n>1)
        {
            int cnt=0, prime=vis[n];
            while (n%prime==0)
            {
                cnt++;
                n/=prime;
            }
            ans*=cnt+1;
        }
        cout << ans << endl;
    }

    return 0;
}

/*
3
16
17
18
*/