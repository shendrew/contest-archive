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
int n, t, ans;
int prefix[100001];

int main()
{
    cin >> n >> t;
    vector<int> v(n+1);
    for (int i=1; i<=n; i++)
    {
        cin >> v[i];
        prefix[i]=prefix[i-1]+v[i];
    }
    int l=1, r=1;
    while (r<=n)
    {
        if (prefix[r]-prefix[l-1]>t)
        {
            l++;
        }
        else
        {
            ans=max(ans, r-l+1);
            r++;
        }
        r=max(l, r);
    }

    cout << ans << endl;

    return 0;
}

/*
4 5
3 1 2 1
*/