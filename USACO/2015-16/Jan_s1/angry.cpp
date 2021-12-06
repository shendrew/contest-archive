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

ifstream fin("angry.in");
ofstream fout("angry.out");

#define f first
#define s second
#define ll long long

int n, k;
vector<int> v;

bool check(int r)
{
    int pre=v[0], cow=1;
    for (int i=1; i<n; i++)
    {
        if (v[i]-pre>2*r)
        {
            cow++;
            pre=v[i];
        }
    }
    return cow<=k;
}

int main()
{
    fin >> n >> k;
    v.resize(n);
    for (int i=0; i<n; i++)
    {
        fin >> v[i];
    }
    sort(v.begin(), v.end());

    int low=0, high=1e9+1, mid;
    while (low<high)
    {
        mid=low+(high-low)/2;
        if (check(mid))
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    fout << mid << endl;

    return 0;
}