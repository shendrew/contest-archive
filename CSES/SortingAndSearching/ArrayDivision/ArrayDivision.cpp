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

int n, k;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    
    long long low=1, high=1e15, mid;
    while (low<high)
    {
        mid=low+(high-low)/2;
        long long cur=0, count=1;
        bool possible=true;
        for (int i=0; i<n; i++)
        {
            if (v[i]>mid)
            {
                possible=false;
                break;
            }
            if (cur+v[i]>mid)
            {
                cur=v[i];
                count++;
                continue;
            }
            cur+=v[i];
        }
        if (count<=k && possible)
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    cout << mid << endl;

    return 0;
}

/*
5 3
2 4 7 3 5
*/