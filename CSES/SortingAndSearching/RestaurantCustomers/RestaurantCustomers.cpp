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
int n, ans;

int main()
{
    cin >> n;
    vector<vector<int>> v;
    for (int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, 0});
    }

    sort(v.begin(), v.end());

    int counter=0;
    for (int i=0; i<v.size(); i++)
    {
        if (v[i][1])
        {
            counter++;
        }
        else
        {
            counter--;
        }
        ans=max(ans, counter);
    }
    cout << ans << endl;

    return 0;
}

/*
3
5 8
2 4
3 9
*/