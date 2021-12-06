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
int t;

int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i=1; i<=n; i++)
        {
            v.push_back(i);
        }
        for (int i=0; i<n/2; i++)
        {
            int temp=v[2*i];
            v[2*i]=v[2*i+1];
            v[2*i+1]=temp;
        }
        if (n%2) // odd
        {
            int temp=v[n-2];
            v[n-2]=v[n-1];
            v[n-1]=temp;
        }
        for (auto &i: v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
2
2
3
*/