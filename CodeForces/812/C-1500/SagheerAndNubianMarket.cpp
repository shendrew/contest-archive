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
int n, m, ans, total=1000000001;
int a[100000];

int main()
{
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int low=0, high=n, mid, cost, num;
    while (low!=high)
    {
        mid=(low+high+1)/2;
        vector<int> v;
        for (int i=0; i<n; i++)
        {
            v.push_back(a[i]+(i+1)*mid);
        }
        sort(v.begin(), v.end());
        cost=0, num=0;
        for (int i=0; i<mid; i++)
        {
            cost+=v[i];
            if (cost>m)
            {
                break;
            }
            num++;
        }
        if (num==mid)
        {
            if (num==ans)
            {
                total=min(total, cost);
            }
            else if (num>ans)
            {
                ans=num;
                total=cost;
            }
            low=mid;
        }
        else
        {
            high=--mid;
        }
    }

    if (ans==0)
    {
        total=0;
    }

    cout << ans << " " << total << endl;

    return 0;
}

/*
3 11
2 3 5
*/