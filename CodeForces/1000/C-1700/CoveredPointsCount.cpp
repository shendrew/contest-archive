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

int n;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    map<long long, int> cnt;
    set<long long> points;
    for (int i=0; i<n; i++)
    {
        long long a, b;
        cin >> a >> b;
        points.insert(a);
        points.insert(b+1);
        cnt[a]++;
        cnt[b+1]--;
    }

    points.insert(-1);

    map<int, long long> ans;
    int segment=0;
    for (auto it=points.begin(); it!=prev(points.end()); it++)
    {
        segment+=cnt[*it];
        ans[segment]+=*next(it)-*it;
    }

    for (int i=1; i<=n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
3
0 3
1 3
3 8
*/