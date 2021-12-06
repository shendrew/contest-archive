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

int n, x, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    multiset<int> child;
    for (int i=0; i<n; i++)
    {
        int pi;
        cin >> pi;
        child.insert(pi);
    }

    while (child.size())
    {
        ans++;
        int cur=*child.begin();
        child.erase(child.begin());
        if (child.upper_bound(x-cur)==child.begin())
        {
            continue;
        }
        child.erase(prev(child.upper_bound(x-cur)));
    }

    cout << ans << endl;

    return 0;
}

/*
4 10
7 2 3 9
*/