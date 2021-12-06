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

int n;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> ans={{v[0]}};
    for (int i=1; i<n; i++)
    {
        int low=0, high=ans.size()-1, mid=low+(high-low)/2;
        while (low<high)
        {
            mid=low+(high-low)/2;
            if (v[i]>ans[mid][ans[mid].size()-1])
            {
                high=mid;
            }
            else
            {
                low=++mid;
            }
        }
        if (v[i]>ans[mid][ans[mid].size()-1])
        {
            ans[mid].push_back(v[i]);
        }
        else
        {
            ans.push_back({v[i]});
        }
    }

    for (auto &i: ans)
    {
        for (auto &j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
5
1 3 2 5 4
*/