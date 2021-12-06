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

long long n, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i].f >> v[i].s;
    }
    sort(v.begin(), v.end());

    long long time=0;
    for (int i=0; i<n; i++)
    {
        time+=v[i].f;
        ans+=v[i].s-time;
    }

    cout << ans << endl;

    return 0;
}

/*
3
6 10
8 15
5 12
*/