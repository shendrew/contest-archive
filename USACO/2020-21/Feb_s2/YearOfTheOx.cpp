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
int n, k, ans;
int a[100000];
vector<pair<int,int>> v;
set<pair<int,int>> portal;

int main()
{
    cin >> n >> k;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for (int i=0; i<n; i++)
    {
        v.push_back({a[i]/12*12, (a[i]/12+(a[i]%12!=0))*12});
    }
    sort(v.begin(), v.end());

    for (auto &i: v)
    {
        portal.insert(i);
    }
    
    vector<int> space;
    int pre=0;
    for (auto &i: portal)
    {
        ans+=(i.f-pre)+(max(i.s-i.f, 0));
        space.push_back(i.f-pre);
        pre=i.s;
    }

    sort(space.begin(), space.end());
    reverse(space.begin(), space.end());
    for (int i=0; i<k-1; i++)
    {
        if (i>=space.size())
        {
            break;
        }
        ans-=space[i];
    }

    cout << ans << endl;
    return 0;
}
/*
5 3
101
85
100
46
95
*/