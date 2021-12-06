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
int n, x;
long long ans;
map<long long, int> occ;

int main()
{
    cin >> n >> x;
    vector<long long> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    occ[0]=1;
    long long sum=0;
    for (int i=0; i<n; i++)
    {
        sum+=v[i];
        ans+=occ[sum-x];
        occ[sum]++;
    }

    cout << ans << endl;

    return 0;
}

/*
5 7
2 4 1 2 7
*/