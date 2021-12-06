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

int n, type, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> type >> n;
    vector<int> d(n), p(n);
    for (int i=0; i<n; i++)
    {
        cin >> d[i];
    }
    for (int i=0; i<n; i++)
    {
        cin >> p[i];
    }
    sort(d.begin(), d.end());
    sort(p.begin(), p.end());
    if (type==2)
    {
        reverse(p.begin(), p.end());
    }
    for (int i=0; i<n; i++)
    {
        ans+=max(d[i], p[i]);
    }
    cout << ans << endl;

    return 0;
}

/*
1
3
5 1 4
6 2 4
*/