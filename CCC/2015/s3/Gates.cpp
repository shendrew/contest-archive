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

int g, p, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> g >> p;
    set<int> gates;
    for (int i=1; i<=g; i++)
    {
        gates.insert(i);
    }
    vector<int> planes(p);
    for (int i=0; i<p; i++)
    {
        cin >> planes[i];
    }

    for (int i=0; i<p; i++)
    {
        auto choose=gates.upper_bound(planes[i]);
        if (choose==gates.begin())
        {
            break;
        }
        gates.erase(prev(choose));
        ans++;
    }
    cout << ans << endl;

    return 0;
}

/*
4
3
4
1
1
*/