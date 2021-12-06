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

int n;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> v(10);
    vector<pair<int,int>> digit;
    for (int i=1; i<=9; i++)
    {
        cin >> v[i];
        digit.push_back({n/v[i], i});
    }
    sort(digit.begin(), digit.end(), greater<pair<int,int>>());

    int len=digit[0].f, val=0;
    if (len==0)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i=0; i<9; i++)
    {
        if (digit[i].f==digit[0].f)
        {
            val=digit[i].s;
        }
    }
    vector<int> ans;
    for (int i=0; i<len; i++)
    {
        ans.push_back(val);
    }

    int leftover=n%v[val];
    for (int i=0; i<len; i++)
    {
        int cur=val;
        for (int j=val+1; j<=9; j++)
        {
            if (leftover+v[val]>=v[j])
            {
                cur=j;
            }
        }
        leftover+=v[val]-v[cur];
        ans[i]=cur;
    }

    for (auto &i: ans)
    {
        cout << i;
    }
    cout << endl;

    return 0;
}

/*
5
5 4 3 2 1 2 3 4 5
*/