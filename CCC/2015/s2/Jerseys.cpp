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

int n, a, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> a;
    vector<int> jersey(n);
    for (int i=0; i<n; i++)
    {
        char j;
        cin >> j;
        if (j=='S')
        {
            jersey[i]=0;
        }
        else if (j=='M')
        {
            jersey[i]=1;
        }
        else
        {
            jersey[i]=2;
        }
    }

    vector<pair<int, int>> request(a);
    for (int i=0; i<a; i++)
    {
        char j;
        cin >> j >> request[i].f;
        if (j=='S')
        {
            request[i].s=0;
        }
        else if (j=='M')
        {
            request[i].s=1;
        }
        else
        {
            request[i].s=2;
        }
    }
    sort(request.begin(), request.end());

    vector<int> done(n);
    for (int i=0, j=0; i<request.size(); i++)
    {
        if (!done[request[i].f])
        {
            if (request[i].s<=jersey[request[i].f-1] && request[i].f<=n)
            {
                ans++;
            }
            done[request[i].f]++;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
4
3
M
S
S
L
L 3
S 3
L 1
*/