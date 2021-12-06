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
int t, x, sum;
vector<int> ans;
int visit[100];

int solve(int n, vector<int> test)
{
    if (n<0 || n==x)
    {
        return 0;
    }
    if (n==sum)
    {
        cout << "YES" << endl;
        for (auto &i: ans)
        {
            cout << i << " ";
        }
        cout << endl;
        return 1;
    }
    for (int i=0; i<test.size(); i++)
    {
        if (!visit[i])
        {
            visit[i]=1;
            ans.push_back(test[i]);
            if (solve(n+test[i], test))
            {
                ans.pop_back();
                visit[i]=0;
                return 1;
            }
            ans.pop_back();
            visit[i]=0;
        }
    }
    return 0;
}

int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        sum=0;
        cin >> n >> x;
        vector<int> v(n);

        for (int i=0; i<n; i++)
        {
            cin >> v[i];
            sum+=v[i];
        }
        if (sum==x)
        {
            cout << "NO" << endl;
        }
        else if (sum<x)
        {
            cout << "YES" << endl;
            for (auto &i: v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            ans.clear();
            if (!solve(0, v))
            {
                cout << "NO" <<endl;
            }
        }
    }

    return 0;
}

/*
3
3 2
3 2 1
5 3
1 2 3 4 8
1 5
5

1
3 3
3 2 1
*/