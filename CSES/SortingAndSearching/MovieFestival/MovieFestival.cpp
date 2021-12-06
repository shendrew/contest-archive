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

int n, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<pair<int,int>> v(n+1);
    for (int i=1; i<=n; i++)
    {
        cin >> v[i].s >> v[i].f;
    }
    sort(v.begin(), v.end());
    
    int pre=0;
    for (int i=1; i<=n; i++)
    {
        if (v[i].s >= v[pre].f)
        {
            ans++;
            pre=i;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
3
3 5
4 9
5 8
*/