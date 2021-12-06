#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

#define f first
#define s second
int n, q;
long long ans;
long long a[200000], prefix[200002];

int main()
{
    cin >> n >> q;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for (int i=0; i<q; i++)
    {
        int l, r;
        cin >> l >> r;
        prefix[l]++;
        prefix[r+1]--;
    }


    vector<int> occ;
    for (int i=1; i<=n; i++)
    {
        prefix[i]+=prefix[i-1];
        occ.push_back(prefix[i]);
    }

    sort(a, a+n, greater<long long>());
    sort(occ.begin(), occ.end(), greater<int>());

    for (int i=0; i<n; i++)
    {
        ans+=a[i]*occ[i];
    }

    cout << ans << endl;
    return 0;
}

/*
5 3
5 2 4 1 3
1 5
2 3
2 3
*/