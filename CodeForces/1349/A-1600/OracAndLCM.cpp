#include <iostream>
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
int n;
int a[100001];
vector<long long> v;

int solve()
{
    int div=v[0];
    for (int i=1; i<v.size(); i++)
    {
        div=gcd(div, v[i]);
        if (div==1)
        {
            return 1;
        }
    }
    return div;
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    set<long long> uni;
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            long long len=uni.size();
            long long ai=lcm(a[i], a[j]);
            uni.insert(ai);
            if (len!=uni.size())
            {
                v.push_back(ai);
            }
        }
    }

    cout << solve() << endl;

    return 0;
}

/*
10
540 648 810 648 720 540 594 864 972 648
*/