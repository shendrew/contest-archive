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
int n, d;
long long ans;
pair<int, int> a[100001];
long long prefix[100001];

int main()
{
    cin >> n >> d;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i].f >> a[i].s;
    }

    sort(a+1, a+n+1);
    for (int i=1; i<=n; i++)
    {
        prefix[i]=prefix[i-1]+a[i].s;
    }

    for (int i=1; i<=n; i++)
    {
        int mini=i, maxi=n, mid=(mini+maxi+1)/2;
        while (mini!=maxi)
        {
            if (a[i].f+d>a[mid].f)
            {
                mini=mid;
            }
            else
            {
                maxi=--mid;
            }
            mid=(mini+maxi+1)/2;
        }
        ans=max(ans, prefix[mid]-prefix[i-1]);
    }

    cout << ans << endl;

    return 0;
}

/*
5 100
0 7
11 32
99 10
46 8
87 54

5 1
5 9
2 10
8 5
18 12
1 1
*/